
#include"Renderer.h"


Renderer::Renderer(){
	VertexShader 
		 entityVertex =  VertexShader("./src/game/shaders/vertex.glsl"),
		 terrainVertex = VertexShader("./src/game/shaders/terrainvertex.glsl"),
		 skyboxVertex =  VertexShader("./src/game/shaders/skyboxvertex.glsl");
	FragmentShader
		 entityFragment = FragmentShader("./src/game/shaders/fragment.glsl"),
		 terrainFragment = FragmentShader("./src/game/shaders/terrainfragment.glsl"),
		 skyboxFragment =  FragmentShader("./src/game/shaders/skyboxfragment.glsl"),
		 outlineFragment =  FragmentShader("./src/game/shaders/outlinefragment.glsl");
	Shader
		* entityShader = new Shader(&entityVertex, &entityFragment),
		* terrainShader = new Shader(&terrainVertex, &terrainFragment),
		* skyboxShader = new Shader(&skyboxVertex, &skyboxFragment),
		* outlineShader = new Shader(&terrainVertex, &outlineFragment);

	//delete entityVertex, terrainVertex, skyboxVertex, entityFragment, terrainFragment, skyboxFragment, outlineFragment;

	entityRenderer=new EntityRenderer(entityShader);
	terrainRenderer = new TerrainRenderer(terrainShader,outlineShader);
	skyboxRenderer = new SkyBoxRenderer(skyboxShader);
}

void Renderer::renderEntities(std::vector<Entity*> entities) {
	for (Entity* entity : entities) 
		entityRenderer->renderEntity(entity);
}	

void Renderer::renderSkybox(SkyBox* skybox) {
	skyboxRenderer->renderSkyBox(skybox);
}

void Renderer::updateMatrix(glm::mat4 projectionMatrix, glm::mat4 viewMatrix ,bool up) {
	terrainRenderer->shader->activate();
	terrainRenderer->shader->setMat4("projectionMat", projectionMatrix);
	terrainRenderer->shader->setMat4("viewMat", viewMatrix);
	
	terrainRenderer->outlineShader->activate();
	terrainRenderer->outlineShader->setMat4("projectionMat", projectionMatrix);
	terrainRenderer->outlineShader->setMat4("viewMat", viewMatrix);
	
	entityRenderer->shader->activate();
	entityRenderer->shader->setMat4("projectionMat", projectionMatrix);
	entityRenderer->shader->setMat4("viewMat", viewMatrix);

	skyboxRenderer->shader->activate();
	skyboxRenderer->shader->setMat4("projectionMat", projectionMatrix);
	skyboxRenderer->shader->setMat4("viewMat", glm::mat4(glm::mat3(viewMatrix)));
}

void Renderer::renderTerrains(std::vector<Terrain*> terrains,bool isselected) {
	
	glStencilOp(GL_REPLACE, GL_KEEP, GL_REPLACE);
	glStencilFunc(GL_NOTEQUAL, 1, 0xFF);
	glEnable(GL_STENCIL_TEST);
	glStencilMask(1);//always draw but set to 1;
	for (Terrain* terrain : terrains) {
		terrainRenderer->renderTerrain(terrain);
		//terrain->increaseScale(0.00013f);
	}
	glStencilMask(0);
	glDisable(GL_STENCIL_TEST);

	if (isselected) {
		//glDisable(GL_DEPTH_TEST);
		glEnable(GL_STENCIL_TEST);
		glStencilFunc(GL_EQUAL, 0,0xFF);//draw if value=0 , writing is disabled;

		for (Terrain* terrain : terrains) {
			terrainRenderer->renderOutlinedTerrain(terrain);
		}
		glDisable(GL_STENCIL_TEST);
		glEnable(GL_DEPTH_TEST);
	}
	//terrains[0]->increaseScale(-0.00013f);

}

void Renderer::loadLights(std::vector<Light*> lights,Material* mtl) {
	Shader* shader = entityRenderer->shader;
	shader->activate();
	//shader->setFloat("material.shininess", mtl->shininess);
	for (Light* light : lights) {
		shader->setVec3("light.ambient", light->material->ambient);
		shader->setVec3("light.diffuse", light->material->diffuse);
		shader->setVec3("light.specular", light->material->specular);
		shader->setFloat("light.shininess", light->material->shininess);
	}
	shader = terrainRenderer->shader;
	shader->activate();
	//shader->setFloat("material.shininess", mtl->shininess);
	for (Light* light : lights) {
		shader->setVec3("light.ambient", light->material->ambient);
		shader->setVec3("light.diffuse", light->material->diffuse);
		shader->setVec3("light.specular", light->material->specular);
		shader->setFloat("light.shininess", light->material->shininess);
	}
	
}

Renderer::~Renderer() {
	delete entityRenderer;
	delete terrainRenderer;
	delete skyboxRenderer; 
		std::cout << "renderer ";
}

