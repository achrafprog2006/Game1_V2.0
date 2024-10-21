
#include"MeshFactory.h"
#include<iostream>

MeshFactory::MeshFactory() {
	 cube = new Mesh(Loader::loadAchrafFile("resources/box1.achraf"));
     terrain = Loader::generateTerrain(30, 20, "resources/heightMap0x.png", 5);
}

MeshFactory::~MeshFactory() {
	delete cube,terrain;
	std::cout << "hahah"<<cube<<"..."<<terrain;
}