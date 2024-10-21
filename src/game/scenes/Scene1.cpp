#include"Scene.h"
#include"../loaders/Loader.h"
#include"../../headers/Achraf.h"
#include"../objects/Material.h"
#include"../../headers/Materials.h"
#include"../window/Window.h"
#include<glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include<iostream>
#include<cmath>

template<>
std::vector<Entity*> Scene<1>::generate() {
    std::vector<Entity*> v;
    
    DataPack* data = Loader::loadAchrafFile("resources/box1.achraf");
    Texture* texture1 = new Texture("resources/Rana.png"),
        * texture2 = new Texture("resources/box1.png"),
        * texture3 = new Texture("resources/ab.png"),
        * texture4 = new Texture("resources/jn.jpg"),
        * texture5 = new Texture("resources/bn.png"),
    *texture6 = new Texture("resources/ta.png");
   
    for (int i = 0; i < 1000; i++) {
        Mesh* cubeMesh = new Mesh(data);
        Texture* texture=nullptr;
        if (i % 4 == 1)texture = texture3;
        if (i % 4 == 2) texture = texture4;
        if (i % 4 == 3) texture = texture5;
        if (i%4==0) texture = texture6;
        cubeMesh->setTexture(texture,0);
        v.push_back(new Entity(cubeMesh, glm::vec3(Achraf::randa() * 400 - 200, Achraf::randa()*300-150, Achraf::randa() * -100 -15),1+Achraf::randa()*4));
    }
        return v;
}
float r[40] ;

template<>
Scene<1>::Scene(Window* window) :window(window) {
    camera = new Camera();
    panel = new Panel(window->window);
    meshFactory = new MeshFactory();

    DataTexture** textures = new DataTexture* [6]{
     new DataTexture("resources/skybox/right.jpg"),
     new DataTexture("resources/skybox/left.jpg"),
      new DataTexture("resources/skybox/top.jpg"),
    new  DataTexture("resources/skybox/bottom.jpg"),
    new  DataTexture("resources/skybox/front.jpg"),
    new  DataTexture("resources/skybox/back.jpg")
    };
     projectionMat = glm::perspective(glm::radians(45.0f /*panel->data["fov"]*/), (float)window->SCR_WIDTH / (float)window->SCR_HEIGHT, 0.01f /*panel->data["near"]*/, 70.0f /*panel->data["far"]*/);


    Material* mtlL = &Materials::Light1;
    Material* mtl = &Materials::gold;
    Light* l1 = new Light(glm::vec3(500, 150, 500), glm::vec3(1), mtlL);
    lights.push_back(l1);
    Texture* texture1 = new Texture("resources/resp2_diff.png");
    Texture* texture2 = new Texture("resources/grassy3.png");
    Texture* texture3 = new Texture("resources/ab_diff.png");
    Texture* spec = new Texture("resources/spec_white.png");

    Mesh* cubeMesh = meshFactory->cube;
    Mesh* terrainMesh = meshFactory->terrain;

    //DataPack* d = ObjLoader::loadAchrafFile("resources/earth.achraf");
    cubeMesh->setTexture(texture3, 0);
    cubeMesh->setTexture(spec, 1);
    terrainMesh->setTexture(texture2, 0);
    terrainMesh->setTexture(spec, 1);
    Entity* cube2 = new Entity(cubeMesh, glm::vec3(0.05f, 0.1, 0), 0.002);
    Entity* cube3 = new Entity(cubeMesh, glm::vec3(-0.05f, 0.1, 0.005), 0.015);
    Entity* cube4 = new Entity(cubeMesh, glm::vec3(0, 0, 20), 1);
    Entity* cube = new Entity(cubeMesh, glm::vec3(0, 0.1, 0), 0.001);

    Terrain* t = new Terrain(terrainMesh,glm::vec3(0));
    Terrain* t2 = new Terrain(terrainMesh, glm::vec3(-30, 0, 30));
    Terrain* t3 = new Terrain(terrainMesh, glm::vec3(-30, 0, 0));
    Terrain* t4 = new Terrain(terrainMesh, glm::vec3(0, 0,30 ));
    /*
    Terrain* t5 = new Terrain(terrainMesh, glm::vec3(0, 0, -900));
    Terrain* t6 = new Terrain(terrainMesh, glm::vec3(-900, 0, -900));
    Terrain* t7 = new Terrain(terrainMesh, glm::vec3(-900, 0, 0));*/


    entities.push_back(cube);
    entities.push_back(cube2);
    entities.push_back(cube3);
    entities.push_back(cube4);

    terrains.push_back(t);
     terrains.push_back(t2);
    terrains.push_back(t3);
    terrains.push_back(t4);
    /*terrains.push_back(t5);
    terrains.push_back(t6);
    terrains.push_back(t7);*/

    skybox = new SkyBox(textures);

    //entities = generate();
    renderer = new Renderer();
    std::cout << "game is starting ...." << std::endl;
    renderer->loadLights(lights, mtl);

}




template<>
void Scene<1>::renderScene() {
    panel->render();
    glClearColor(0,1,0, 1);
    glStencilMask(1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    glStencilMask(0);
    glDepthFunc(GL_LEQUAL);
    //lights[0]->position = *(camera->position);
    //std::cout << lights[0]->position.x<<","<< lights[0]->position.y<<","<< lights[0]->position.z << std::endl;
    renderer->updateMatrix(projectionMat,camera->getViewMatrix(),true/*panel->data["up"]*/);
    renderer->entityRenderer->shader->activate();
   renderer->entityRenderer->shader->setVec3("viewPos", *(camera->position));
   renderer->entityRenderer->shader->setFloat("n", panel->data["n"]);


   entities[0]->increaseRotation(0.1f, 0.25f, 0);
          
   //entities[0]->setPosition(glm::vec3(panel->data["x"], panel->data["y"], panel->data["z"]) );
   //renderer->entityRenderer->shader->setVec3("light.ambient", glm::vec3(panel->data["xa"], panel->data["ya"], panel->data["za"]));
   //renderer->entityRenderer->shader->setVec3("light.specular", glm::vec3(panel->data["xs"], panel->data["ys"], panel->data["zs"]));
   //renderer->entityRenderer->shader->setVec3("light.diffuse", glm::vec3(panel->data["xd"], panel->data["yd"], panel->data["zd"]));
       //renderer->entityRenderer->shader->activate();
    renderer->terrainRenderer->shader->activate();
    renderer->terrainRenderer->shader->setVec3("viewPos", *(camera->position));
    renderer->terrainRenderer->shader->setVec3("light.position", *(camera->position));
   renderer->terrainRenderer->shader->setFloat("far", panel->data["far"]);
   renderer->terrainRenderer->shader->setFloat("near", panel->data["near"]);
   renderer->terrainRenderer->shader->setFloat("width", panel->data["width"]);
   renderer->terrainRenderer->shader->setFloat("height", panel->data["height"]);


   renderer->renderEntities(entities);
   renderer->renderSkybox(skybox);
   renderer->renderTerrains(terrains,panel->data["select"]);


    panel->update();
}
template<>
Scene<1>::~Scene() {
    std::cout << "scene1mchat";
    panel->destroy();
    for (Entity* entity : entities) {
        delete entity;    std::cout << "haw" << std::endl;

    }
    delete renderer , camera,panel ,skybox;
    delete meshFactory;

    
}