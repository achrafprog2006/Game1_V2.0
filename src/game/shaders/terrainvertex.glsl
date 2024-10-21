#version 330 core

  layout(location=0)in vec3 pos;
  layout(location=1)in vec2 texCoord;
  layout(location=2)in vec3 normal;

out vec2 pass_texCoord;
out vec3 FragPos;
out vec3 Normal;

uniform mat4 transformationMat;
uniform mat4 projectionMat;
uniform mat4 viewMat;

uniform float isOutlined;

void main(){

   pass_texCoord = texCoord;
   FragPos= vec3( transformationMat* vec4(pos,1.0) );
   Normal = mat3(transpose(inverse(transformationMat))) * normal;

   if(isOutlined==1)
      gl_Position =  projectionMat*viewMat*transformationMat*vec4(pos+normal,1.0);  
   else
  gl_Position =  projectionMat*viewMat*transformationMat*vec4(pos,1.0);  
    
}