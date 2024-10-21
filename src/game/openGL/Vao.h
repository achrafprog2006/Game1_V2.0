#pragma once
#include <glad/glad.h>
class Vao {

 private:
    unsigned int id;
    int attributes = -1;
public:
    Vao();
    ~Vao();
    void use();
    void disuse();
    void point(GLuint location ,GLuint size,GLuint Type,GLuint stride , GLuint offset);
    void enable(GLuint location);
    void disable(GLuint location);



};
