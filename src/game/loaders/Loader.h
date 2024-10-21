#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include"../objects/DataTexture.h"

#include"../objects/Mesh.h"

class Loader {
public:
	 static DataPack* loadAchrafFile(const char* filename);
	 static Mesh* generateTerrain(int size ,int unit, const char* heightMap ,float maxHeight);
	 static Mesh* generateTerrain2(int size, int unit, const char* heightMap, float maxHeight);

	 Loader();
};