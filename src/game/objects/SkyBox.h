#pragma once
#include"../openGL/Texture3D.h"
#include"../openGL/Vao.h"
#include"../openGL/Vbo.h"
#include"DataTexture.h"
class SkyBox {
public:
	SkyBox(DataTexture** textures);
	Texture3D* texture;
	float* mesh;
	Vao* vao;
	Vbo* vbo;
	~SkyBox();

};