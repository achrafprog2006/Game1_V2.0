#include"Window.h"
#include <iostream>
int Window::SCR_HEIGHT = 600;
int Window::SCR_WIDTH = 800;
bool Window::action = false;
void Window::frameBufferSizeCallBack(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
    SCR_HEIGHT = height;
    SCR_WIDTH = width;
    action = true;
}
Window::Window() : window(nullptr){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}
bool Window::init(int width , int height, const char* title) {
    SCR_HEIGHT = height;
    SCR_WIDTH = width;
    window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, title, NULL, NULL);
    if (!window)return false;
    glfwMakeContextCurrent(window);
    return true;
}

void Window::setParameters() {
    glViewport(0, 0,SCR_WIDTH ,SCR_HEIGHT);
   glfwSetFramebufferSizeCallback(window,Window::frameBufferSizeCallBack);
}
bool Window::shouldClose() {
    return glfwWindowShouldClose(window);
}
void Window::close() {
    glfwSetWindowShouldClose(window, true);
}
void Window::updateFrame() {
    glfwSwapBuffers(window);
    glfwPollEvents();
}
void Window::terminate() {
    glfwTerminate();
}
