#include"Scene.h"
#include"../loaders/Loader.h"
#include"../../headers/Achraf.h"
#include"../objects/Material.h"
#include"../../headers/Materials.h"
#include<iostream>
#include<cmath>
template<>
std::vector<Entity*> Scene<2>::generate() {
    std::vector<Entity*> v;
    Texture* texture1 = new Texture("resources/bn.png");
    DataPack* data = Loader::loadAchrafFile("resources/box1.achraf");
    Mesh* cubeMesh = new Mesh(data);
    cubeMesh->setTexture(texture1,0);
    v.push_back(new Entity(cubeMesh,glm::vec3(0),2));
    return v;
}
template<>
Scene<2>::Scene(Window* window) :window(window) {
    camera = new Camera();
    Material* mtlL = &Materials::Light1;
    Material* mtl = &Materials::gold;
    Light* l1 = new Light(glm::vec3(0), glm::vec3(1), mtlL);
    lights.push_back(l1);
    
    entities = generate();
    renderer = new Renderer();
    renderer->loadLights(lights, mtl);
    renderer->entityRenderer->shader->setVec3("viewPos", *(camera->position));

}
template<>
void Scene<2>::renderScene() {
    glClearColor(0.1f, 0.1f, 0.2f, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    lights[0]->position = *(camera->position);
    std::cout << lights[0]->position.x << "," << lights[0]->position.y << "," << lights[0]->position.z << std::endl;
    renderer->entityRenderer->shader->setMat4("viewMat", camera->getViewMatrix());
    renderer->entityRenderer->shader->setVec3("light.position", *(camera->position));
    
    renderer->renderEntities(entities);
}
template<>
Scene<2>::~Scene() {
    std::cout << "scenemchat";
    for (Entity* entity : entities)
        delete entity;
    delete renderer;
    delete camera;
}