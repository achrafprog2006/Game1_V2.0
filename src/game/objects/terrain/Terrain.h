#pragma once

#include <glm/glm.hpp>

#include "../../objects/Mesh.h"
#include"../../openGL/Texture.h"
class Terrain {

public:
	Mesh* mesh;
	Texture* diffuseTex;
	Texture* specularTex;
	Texture* hightMapTex;
	float scale;
	glm::vec3 position;
	glm::mat4 getModelMatrix();
	void increaseScale(float dS);
	Terrain(Mesh* mesh, glm::vec3 position);
	~Terrain();





};