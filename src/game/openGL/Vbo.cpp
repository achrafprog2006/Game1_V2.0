#include "Vbo.h"
#include<iostream>

 Vbo::Vbo() {
     glGenBuffers(1, &id);
}
void Vbo::use() {
    glBindBuffer(GL_ARRAY_BUFFER, id);
}
void Vbo::fill(float* data, int size) {
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

Vbo::~Vbo() {
    glDeleteBuffers(1, &id);
    std::cout << "mchavbo";
}
