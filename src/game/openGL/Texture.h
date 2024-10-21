#pragma once

#include<stb/stb_image.h>
#include<glad/glad.h>
#include<iostream>

class Texture {
	public:
    GLuint id;
	Texture(const char* filename);
	void use();
	void activateOn(int unit);
	~Texture();





};