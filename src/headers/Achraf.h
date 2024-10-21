#pragma once

#include<time.h>
#include<cmath>
#include<stdlib.h>
#include<iostream>
#include<glad/glad.h>
#include<stb/stb_image.h>

class Achraf {
	public:
		static float a;
	static long long getCurrentTimeMillis();
	static float randa();
	static float rand(float start , float end);
	static void printOpenGLinfo();
	static void write(unsigned char* data);


};




