#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include<iostream>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<stb/stb_image.h>
#include<fstream>
#include<sstream>
#include<streambuf>
#include<string>
#include<stdio.h>
#include <chrono>
#include <thread>
#include"headers/Achraf.h"
#include"game/scenes/Scene.h"
#include"game/openGL/Vao.h"
#include"game/openGL/Vbo.h"
#include"game/shaders/Shader.h"
#include"game/loaders/Loader.h"
#include"game/window/Window.h"
#include"game/gui/Panel.h"
#include"game/objects/DataTexture.h"
#include<imgui/imgui.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

int SCR_HEIGHT = 600, SCR_WIDTH = 800;
Window* window;
Scene<1>* scene;
int main() {
     window = new Window();
    // window code
    if (!window->init(800,600,"Achraf0x")) {
        std::cout << "rah maymknch !!!" << std::endl;
        window->terminate();
        return -1;
    }
    window->setParameters();
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        return -1;
    glEnable(GL_DEPTH_TEST);
    Achraf::printOpenGLinfo();
    srand(time(NULL));

    scene = new Scene<1>(window);
    scene->renderer->entityRenderer->shader->activate();
  
    const double FPS = 100.0;
    double currentTime ,lastTime = glfwGetTime();
    while (!window->shouldClose()) {
        currentTime = glfwGetTime();
        if (currentTime - lastTime >= 1.0 / FPS)
        {
            if (window->action) { window->action = false;          
            std::cout << (float)window->SCR_WIDTH << (float)window->SCR_HEIGHT << std::endl;
            }
    //-------------------------------------------------
            lastTime = currentTime;
            processInput(window->window);
            scene->renderScene();

            window->updateFrame();
    //------------------------------------------------
        }
    }
   delete scene;
   delete window;
    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow* window) {
    Camera* cam = scene->camera;
    float factor = 1.0f;
    Texture* t = scene->terrains[0]->mesh->textures[0];
    t->use();
    if (scene->panel->data["less"])
        glDepthFunc(GL_LESS);
    if (scene->panel->data["always"])
        glDepthFunc(GL_ALWAYS);
    if (scene->panel->data["never"])
        glClear(GL_DEPTH_BUFFER_BIT);
    if (scene->panel->data["equal"])
    if (scene->panel->data["greater"])
        glDepthFunc(GL_GREATER);
    if (scene->panel->data["not equal"])
        glDepthFunc(GL_NOTEQUAL);
    if (glfwGetKey(window, GLFW_KEY_1) == 1) {
    }
     if (glfwGetKey(window, GLFW_KEY_2) == 1) {
        
    }
     if (glfwGetKey(window, GLFW_KEY_3) == 1) {
       
    }
     if (glfwGetKey(window, GLFW_KEY_4) == 1) {
       
    }
     if (glfwGetKey(window, GLFW_KEY_W) == 1) {
        cam->increasePosition(0,0,-.03f * factor);
    }
     if (glfwGetKey(window, GLFW_KEY_S) == 1) {
        cam->increasePosition(0, 0, .03f * factor);
    }
     if (glfwGetKey(window, GLFW_KEY_A) == 1) {
        cam->increasePosition(-.03f * factor, 0, 0);
    }
     if (glfwGetKey(window, GLFW_KEY_D) == 1) {
        cam->increasePosition(.03f * factor, 0, 0);
    }
     if (glfwGetKey(window, GLFW_KEY_R) == 1) {
        cam->increasePosition(0,0.03f * factor, 0);
    }
     if (glfwGetKey(window, GLFW_KEY_F) == 1) {
        cam->increasePosition(0,-.03f*factor, 0);
    }
     if (glfwGetKey(window, GLFW_KEY_H) == 1) {
        


    }
     if (glfwGetKey(window, GLFW_KEY_J) == 1) {
         cam->increaseYaw(-3.0f* factor);
    }
     if (glfwGetKey(window, GLFW_KEY_K) == 1) {
         cam->increasePitch(+3.0f* factor);
     }
     if (glfwGetKey(window, GLFW_KEY_I) == 1) {
         cam->increasePitch(-3.0f* factor);
    }
     if (glfwGetKey(window, GLFW_KEY_L) == 1) {
         cam->increaseYaw(+3.0f* factor);
     }
     if (glfwGetKey(window, GLFW_KEY_SPACE) == 1) {
       // Achraf::a *=-1.0f;
        glfwSetWindowShouldClose(window,true);
    }

  
   
}
