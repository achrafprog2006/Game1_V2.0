#include "Terrain.h"



Terrain::Terrain(Mesh* mesh, glm::vec3 position):mesh(mesh),position(position),scale(1.0f){

}
void Terrain::increaseScale(float dS) {
	scale += dS;
}

glm::mat4 Terrain::getModelMatrix() {
	return glm::scale(glm::translate(glm::mat4(1), position),glm::vec3(scale));
}
Terrain::~Terrain( ) {
	
}