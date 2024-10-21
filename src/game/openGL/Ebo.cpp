#include"Vbo.h"



Ebo::Ebo(){
    glGenBuffers(1, &id);
}
void Ebo::use() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
}
void Ebo::fill(unsigned int* data, int size) {
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}
 Ebo::~Ebo() {
    glDeleteBuffers(1, &id);
}
