#include"EntityRenderer.h"
EntityRenderer::EntityRenderer(Shader*shader):shader(shader){

}


void EntityRenderer::renderEntity(Entity* entity) {
	shader->activate();
	shader->setMat4("transformationMat", entity->getModelMatrix());
	shader->setInt("material.diffuse", 0);
	shader->setInt("material.specular", 1);
	shader->setFloat("material.shininess", 0.5f);
	entity->mesh->enableAttribs();
	glDrawElements(GL_TRIANGLES,entity->mesh->indicesCount,GL_UNSIGNED_INT,(void*)0);
}

void EntityRenderer::renderEntity(Entity* entity,SkyBox* skybox) {
	shader->activate();
	shader->setInt("skybox", 3);
	shader->setMat4("transformationMat", entity->getModelMatrix());
	shader->setInt("material.diffuse", 0);
	shader->setInt("material.specular", 1);
	shader->setFloat("material.shininess", 0.5f);
	entity->mesh->enableAttribs();
	skybox->texture->activateOn(3);
	glDrawElements(GL_TRIANGLES, entity->mesh->indicesCount, GL_UNSIGNED_INT, (void*)0);
}

EntityRenderer::~EntityRenderer() {
	delete shader;
}
