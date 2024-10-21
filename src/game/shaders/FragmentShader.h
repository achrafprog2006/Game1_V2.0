#pragma once

#include<glad/glad.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<fstream>
#include<sstream>
#include<streambuf>
#include<string>
#include<iostream>

class FragmentShader {

public:
	GLuint id;
	FragmentShader(const char* fileName);
	~FragmentShader();



};