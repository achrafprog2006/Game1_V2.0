
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
#include "VertexShader.h"
#include"FragmentShader.h"

class Shader {
public:
	GLuint ID;
	VertexShader* vertexShader;
	FragmentShader* fragmentShader;
	Shader(VertexShader* vertexShader, FragmentShader* fragmentShader);
	~Shader();

	void activate();
	void setMat4(std::string name , glm::mat4 value);
	void setFloat(std::string name, float value);
	void setInt(std::string name, int value);
	void setVec3(std::string name, glm::vec3 value);
	GLuint location(std::string name);
	
	static std::string loadShaderSrc(const char* fileName);
};