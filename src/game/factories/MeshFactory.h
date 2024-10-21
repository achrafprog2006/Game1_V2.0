#pragma once
#include "../objects/Mesh.h"
#include"../loaders/Loader.h"
class MeshFactory {
public:
	MeshFactory();
	 Mesh* cube;
	 Mesh* terrain;
	~MeshFactory();



};