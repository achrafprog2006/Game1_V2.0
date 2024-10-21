#pragma once
#include<imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>
#include<map>
#include <string>

class Panel {
public:
	std::map<std::string, float>data;
	Panel(GLFWwindow* window);
	void initPanel();
	void floatSlider(float* v);
	void render();
	void destroy();
	void update();
	void initData();
};