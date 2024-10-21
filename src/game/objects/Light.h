#pragma once

#include<glm/glm.hpp>
#include"Material.h"

class Light {
public:
	glm::vec3 position;
	glm::vec3 color;
	Material* material;
	Light(glm::vec3 pos,glm::vec3 color,Material* mat);








};