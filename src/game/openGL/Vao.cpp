 
#include "Vao.h"
#include<iostream>

Vao::Vao() {
	glGenVertexArrays(1, &id);
}
void Vao::use() {
	glBindVertexArray(id);
}
void Vao::disuse() {
	glBindVertexArray(0);
}
void Vao::point(GLuint location, GLuint size, GLenum type, GLuint stride, GLuint offset) {
	glVertexAttribPointer(location, size, type, GL_FALSE, stride,(void*) offset);
}

void Vao::enable(GLuint location) {
	glEnableVertexAttribArray(location);
}
void Vao::disable(GLuint location) {
	glDisableVertexAttribArray(location);
}
Vao::~Vao() {
	glDeleteVertexArrays(1, &id);
	std::cout << "vao mcha";
}