#pragma once
#include"../objects/SkyBox.h"
#include"../shaders/Shader.h"

class SkyBoxRenderer {

public:
	Shader* shader;
	SkyBoxRenderer(Shader* shader);
	~SkyBoxRenderer();
	void renderSkyBox(SkyBox* skybox);

};