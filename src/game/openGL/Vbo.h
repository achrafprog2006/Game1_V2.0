#pragma once
#ifndef VBO_H
#define VBO_H

#include <glad/glad.h>


class Vbo {
public:
    unsigned int id;
    Vbo();
    void use();
    void fill(float* data, int size);
    ~Vbo();
};

class Ebo  {
public:
    unsigned int id;
    Ebo();
    void use();
    void fill(unsigned int* data, int size);
    ~Ebo();
};
#endif