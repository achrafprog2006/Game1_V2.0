#pragma once

#include<glad/glad.h>
#include "../openGL/Vao.h"
#include "../objects/Light.h"
#include"EntityRenderer.h"
#include"TerrainRenderer.h"
#include"SkyBoxRenderer.h"
#include"../objects/SkyBox.h"
#include "../shaders/Shader.h"
#include"../shaders/FragmentShader.h"
#include"../shaders/VertexShader.h"
#include<iostream>

class Renderer {
public:
   
	EntityRenderer* entityRenderer;
	TerrainRenderer* terrainRenderer;
	SkyBoxRenderer* skyboxRenderer;
	Renderer();
	void updateMatrix(glm::mat4 projectionMatrix , glm::mat4 viewMat ,bool up);
	void loadLights(std::vector<Light*> lights, Material* mat);
	void renderEntities(std::vector<Entity*> entities);
	void renderTerrains(std::vector<Terrain*> terrains, bool isselected);
	void renderSkybox(SkyBox* skybox);
	~Renderer();



};