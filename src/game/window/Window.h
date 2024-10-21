#pragma once

#include <GLFW/glfw3.h>

class Window {
	public:
	GLFWwindow* window;
	static int SCR_WIDTH, SCR_HEIGHT;
	static bool action ;
	Window();
	bool init(int width, int hight, const char* title);
	void setParameters();
	bool shouldClose();
	void close();
	void updateFrame();
	static void terminate();
	static void frameBufferSizeCallBack(GLFWwindow* window, int width, int height);









};