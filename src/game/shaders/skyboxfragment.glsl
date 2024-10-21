#version 330 core

in vec3 pass_texCoord;

out vec4 FragColor;

uniform samplerCube skybox;

void main(){
   FragColor=texture(skybox , pass_texCoord);
  // FragColor=vec4(1,0,0,1);
  
}