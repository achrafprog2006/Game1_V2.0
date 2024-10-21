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
uniform float att;

uniform samplerCube skybox;
uniform float n;

void main(){
     //ambien
	
    vec3 ambient = vec3(light.ambient.xy,att) * vec3(texture(material.diffuse,pass_texCoord));

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
	float attenuation =1;
    FragColor = vec4 ( vec3(specular+diffuse+(ambient)*1)*attenuation , 1.0);

	 vec3 reflectionFrag= reflect(-viewDir, normalize(Normal));
	vec3 refractionFrag=  refract(-viewDir, normalize(Normal), (1/n));
	 FragColor = vec4( texture(skybox , refractionFrag ).rgb ,1.0 );
  // FragColor=vec4(Normal,1);
 

}