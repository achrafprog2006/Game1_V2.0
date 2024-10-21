#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include<cmath>
#include <glm/gtc/matrix_transform.hpp>
#include "Mesh.h"

class Entity {

private:
    glm::vec3 position, rotation;
    float scale ,th;
public:
    Entity(Mesh* mes,glm::vec3 pos,float s);
    Mesh* mesh;
    glm::mat4 modelMatrix;

    void increasePosition(float dx, float dy, float dz);
    void increaseRotation(float dx, float dy, float dz);
    void increaseRotation(float dx, float dy, float dz,glm::vec3 axes);
    void increaseRadius(float dr);
    void increaseTheta(float dth);
    void setScale(float s);
    void increaseScale(float ds);
    glm::vec3 getPosition();
    void setPosition(glm::vec3 newPosition);
    glm::vec3 getRotation();
    float getScale();
    void setRotation(glm::vec3 newRotation);
    glm::mat4 getModelMatrix();
    void updateMatrix();
    ~Entity();

   





};
