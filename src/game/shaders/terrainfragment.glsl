#version 330 core

struct Material{
    sampler2D diffuse;
	sampler2D specular;
	float shininess;
};
struct Light{
    vec3 position;
    vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	float shininess;
};


in vec2 pass_texCoord;
in vec3 FragPos;
in vec3 Normal;

out vec4 FragColor;

uniform Light light;
uniform Material material;
uniform vec3 viewPos;

uniform sampler2D texture1;
uniform sampler2D texture2;
uniform float a;
uniform float b;
uniform float c;

uniform float far;
uniform float near;

uniform float height;
uniform float width;


float lin(float depth) 
{
    float z = depth * 2.0 - 1.0; // back to NDC 
    return (2.0 * near * far) / (far + near - z * (far - near));	
}

float lin(float depth , float a , float b) 
{
    float z = depth * 2.0 - 1.0; // back to NDC 
    return (2.0 * a * b) / (b + a - z * (b - a));	
}


void main(){
     //ambient
    vec3 ambient = 0.3*light.ambient * vec3(texture(material.diffuse,pass_texCoord));

	//diffuse
	vec3 norm =normalize(Normal);
	vec3 lightDir =normalize(light.position - FragPos);
	float diff =max( dot(norm,lightDir) ,0.0);
	vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse,pass_texCoord));

	//specular
	vec3 viewDir=normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(-lightDir , norm);
	float spec = pow (max( dot(reflectDir , viewDir) , 0.0 ), material.shininess*128);
	vec3 specular =  light.specular * spec *vec3(texture(material.specular,pass_texCoord));

	float dis = length(FragPos-light.position);
	dis=dis/100;
	float attenuation =  1/(1+b*dis+c*pow(dis,2) );
    FragColor = vec4( (specular+diffuse+ambient)*attenuation , 1.0);
	
	float coord=  gl_FragCoord.x/width;
	if (coord >0.0 && coord <0.05 )FragColor=vec4(vec3(FragColor)+vec3((0.05-coord)*20,0,0) ,1);
    if (coord <1.0 && coord >0.95 )FragColor=vec4(vec3(FragColor)+vec3( (coord-0.95)*20,0,0) ,1);
	coord=  gl_FragCoord.x/width;

	coord=  gl_FragCoord.y/height;
	if (coord >0.0 && coord <0.05 )FragColor=vec4(vec3(FragColor)+vec3(0,0,(0.05-coord)*20) ,1);
    if (coord <1.0 && coord >0.95 )FragColor=vec4(vec3(FragColor)+vec3(0,0, (coord-0.95)*20) ,1);

	float depth = lin(gl_FragCoord.z);
	//FragColor =vec4(0,depth/far,0,1);

	//FragColor=vec4(vec3(specular+diffuse+ambient),1);
   //FragColor=texture(material.diffuse,pass_texCoord);

}