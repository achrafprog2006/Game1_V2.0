#pragma once
#include"../shaders/Shader.h"
#include"../objects/terrain/Terrain.h"


class TerrainRenderer {

public:
	Shader *shader, *outlineShader;
	TerrainRenderer(Shader* shader, Shader* outlineShader);
	~TerrainRenderer();
	void renderTerrain(Terrain* terrain);
	void renderOutlinedTerrain(Terrain* terrain);




};