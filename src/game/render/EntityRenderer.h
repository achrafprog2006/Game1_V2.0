#pragma once

#include<glad/glad.h>
#include"../shaders/Shader.h"
#include"../objects/Entity.h"
#include"../objects/Mesh.h"
#include"../objects/SkyBox.h"
#include"EntityRenderer.h"


class EntityRenderer {
public:
	Shader* shader;
	EntityRenderer(Shader* shader);
	~EntityRenderer();
	void renderEntity(Entity* entity);
	void renderEntity(Entity* entity, SkyBox* skybox);




};