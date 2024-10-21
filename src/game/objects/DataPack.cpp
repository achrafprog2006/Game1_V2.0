#include"DataPack.h"

DataPack::DataPack(float* vertices, int verticesSize,
	float* texCoords, int texCoordsSize,
	float* normals, int normalsSize,
	unsigned int* indices, int indicesSize):
	vertices(vertices) , verticesSize(verticesSize),
	texCoords(texCoords), texCoordsSize(texCoordsSize),
	normals(normals), normalsSize(normalsSize),
	indices(indices), indicesSize(indicesSize)
{}
DataPack::~DataPack() {
	delete[] vertices;
	delete[] indices;
	delete[] normals;
	delete[] texCoords;
}
DataPack::DataPack(){}