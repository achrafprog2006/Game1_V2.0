#pragma once


class DataPack {
public :
	float* vertices, *texCoords, * normals;
	unsigned int* indices;
	int verticesSize, texCoordsSize, normalsSize, indicesSize;
	DataPack(float* vertices,int verticesSize,
		    float* texCoords, int texCoordsSize,
		float* normals, int normalsSize,
		unsigned int* indices, int indicesSize );
	~DataPack();
	DataPack();





};