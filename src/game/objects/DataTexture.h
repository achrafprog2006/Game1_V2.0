#pragma once
#include<iostream>
#include<stb/stb_image.h>
class DataTexture {
 public:
	int width, height, channels;
	unsigned char* data;
	float getValue(float x, float y);
	DataTexture(const char* path);
	~DataTexture();


};