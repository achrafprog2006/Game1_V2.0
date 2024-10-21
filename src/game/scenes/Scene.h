#pragma once
#include"../objects/Camera.h"
#include"../objects/Entity.h"
#include"../objects/Mesh.h"
#include"../render/Renderer.h"
#include"../objects/Material.h"
#include"../objects/Light.h"
#include"../window/Window.h"
#include"../objects/terrain/Terrain.h"
#include<vector>
#include<glad/glad.h>
#include"../gui/Panel.h"
#include"../../headers/Achraf.h"
#include"../objects/SkyBox.h"
#include"../factories/MeshFactory.h"

template<int sceneID>
class Scene {
public:
	Camera* camera;
	Panel* panel;
	MeshFactory* meshFactory;
	static float ff;
	Window* window;
	SkyBox* skybox;
	std::vector<Entity*> entities;
	std::vector<Terrain*> terrains;
	std::vector<Light*> lights;
	Renderer* renderer;
	void renderScene();
	std::vector<Entity*> generate();
	 glm::mat4  projectionMat;
	Scene(Window* window);
	~Scene();
	




};