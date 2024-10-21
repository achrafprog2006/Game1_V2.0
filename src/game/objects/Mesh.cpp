#include"Mesh.h"
#include<iostream>


void  Mesh::enableAttribs() {
	enableDrawData();
	enableTextures();
}
void  Mesh::enableDrawData() {
	vao->use();
	vao->enable(0);
	vao->enable(1);
	vao->enable(2);
	ebo->use();
}

void  Mesh::enableTextures() {
	textures[0]->activateOn(0);
	textures[1]->activateOn(1);
}
void Mesh::setTexture(Texture* texture , int ind) {
	textures[ind] = texture;
}
Mesh::Mesh(DataPack* data) {
	this->data = data;
	vertexCount = data->verticesSize;
	indicesCount = data->indicesSize;
	 
	vao = new Vao();
	ebo = new Ebo();
	Vbo* ver = new Vbo();
	Vbo* tex = new Vbo();
	Vbo* nor = new Vbo();
	vbos.push_back(ver);
	vbos.push_back(tex);
	vbos.push_back(nor);

	vao->use();
	ver->use();
	ver->fill(data->vertices, vertexCount * 3 * sizeof(float));
	vao->point(0, 3, GL_FLOAT, 3 * sizeof(float), 0);
	tex->use();
	tex->fill(data->texCoords, vertexCount * 2 * sizeof(float));
	vao->point(1, 2, GL_FLOAT, 2 * sizeof(float), 0);

	nor->use();
	nor->fill(data->normals, vertexCount * 3 * sizeof(float));
	vao->point(2, 3, GL_FLOAT, 3 * sizeof(float), 0);

	ebo->use();
	ebo->fill(data->indices, indicesCount * sizeof(unsigned int));
	
}
//Mesh::Mesh(float* vertices, float* texCoords,unsigned int* indices, int size, int ind) {}
Mesh::~Mesh() {
	for (Vbo* vbo : vbos) {
		delete vbo;
	}
	delete vao, ebo,data;
	for( int i=0 ; i<2 ; i++)
	  delete textures[i];
}
