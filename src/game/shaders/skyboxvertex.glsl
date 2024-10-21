#version 330 core

layout(location=0)in vec3 pos;

out vec3 pass_texCoord;


uniform mat4 transformationMat;
uniform mat4 projectionMat;
uniform mat4 viewMat;

void main(){

   pass_texCoord = pos;
   vec4 p =  projectionMat*viewMat*transformationMat*vec4(pos*3 ,1.0);  
   gl_Position = p.xyww;
  

}