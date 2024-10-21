#pragma once

#include"../../game/openGL/Vbo.h"
#include"../../game/openGL/Vao.h"
#include"../../game/openGL/Texture.h"
#include"../shaders/Shader.h"
#include"DataPack.h"
#include<vector>
class Mesh {
public:
	void enableAttribs();
	DataPack* data;
	Vao* vao;
	Ebo* ebo;
	std::vector<Vbo*> vbos;
	Texture* textures[2];//1)diffuse / 2)specular
	int vertexCount,indicesCount;
	void setTexture(Texture* texture ,int ind);
	//Mesh(float * vertices,float*texCoords ,unsigned int*indices,int size,int ind);
	void  enableTextures();
	void  enableDrawData();
	Mesh(DataPack* data);
	~Mesh();





};
