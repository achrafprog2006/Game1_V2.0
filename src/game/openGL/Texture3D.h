#pragma once
#include<glad/glad.h>
#include"../objects/DataTexture.h"
class Texture3D {

public:
	GLuint id;
	void use();
	void activateOn(int unit);
	Texture3D(DataTexture** textures);
	~Texture3D();


};