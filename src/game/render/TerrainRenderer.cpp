#include"TerrainRenderer.h"

TerrainRenderer::TerrainRenderer(Shader* shader, Shader* outlineShader) :shader(shader), outlineShader(outlineShader){

}
void TerrainRenderer::renderTerrain(Terrain* terrain) {
	shader->activate();
	shader->setMat4("transformationMat", terrain->getModelMatrix() );
	shader->setInt("material.diffuse", 0);
	shader->setInt("material.specular", 1);
	shader->setFloat("material.shininess",0.5f);
	shader->setFloat("isOutlined", 0);
	terrain->mesh->enableAttribs();
	glDrawElements(GL_TRIANGLES, terrain->mesh->indicesCount, GL_UNSIGNED_INT, (void*)0);
}

void TerrainRenderer::renderOutlinedTerrain(Terrain* terrain) {
	outlineShader->activate();
	outlineShader->setMat4("transformationMat", terrain->getModelMatrix());
	outlineShader->setFloat("isOutlined",1);
	terrain->mesh->enableDrawData();
	glDrawElements(GL_TRIANGLES, terrain->mesh->indicesCount, GL_UNSIGNED_INT, (void*)0);
}

TerrainRenderer::~TerrainRenderer() {
	delete shader , outlineShader;
}