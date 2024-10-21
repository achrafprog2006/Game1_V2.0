#include "SkyBoxRenderer.h"


SkyBoxRenderer::SkyBoxRenderer(Shader* shader): shader(shader) {

}

void SkyBoxRenderer::renderSkyBox(SkyBox* skybox) {
	shader->activate();
	shader->setMat4("transformationMat",glm::mat4(1) );
	skybox->vao->use();
	skybox->texture->use();
	glDrawArrays(GL_TRIANGLES, 0, 36);

}


SkyBoxRenderer::~SkyBoxRenderer() {
	delete shader;
}