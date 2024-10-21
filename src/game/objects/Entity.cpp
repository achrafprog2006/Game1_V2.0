#include"Entity.h"


Entity::Entity(Mesh* m, glm::vec3 pos,float s) : mesh(m) ,position(pos),scale(s),th(0) {
	modelMatrix = glm::mat4(1);
}

void Entity::increasePosition(float dx, float dy, float dz) {
	position += glm::vec3(dx, dy, dz);
	
}
void Entity::increaseRotation(float dx, float dy, float dz) {
	rotation += glm::vec3(dx, dy, dz);
	
}
void Entity::increaseRotation(float dx, float dy, float dz, glm::vec3 axes) {
	rotation += glm::vec3(dx, dy, dz);
	// bdlha mn b3d
}
glm::vec3  Entity::getPosition() {
	return position;
} 
void Entity::increaseRadius(float dr) {
	position = position * dr;
}
void Entity::increaseTheta(float dth) {
	th += dth;
}


glm::vec3  Entity::getRotation() {
	return rotation;
}
void  Entity::setPosition(glm::vec3 newPosition) {
	position = newPosition;
	
}

void  Entity::setRotation(glm::vec3 newRotation) {
	rotation = newRotation;
}

void Entity::setScale(float s) {
	scale = s;
}
void Entity::increaseScale(float ds) {
	scale =scale+ ds;
}
float Entity::getScale() {
	return scale;
}
void Entity::updateMatrix() {
	modelMatrix = glm::rotate(glm::mat4(1), glm::radians(th), glm::vec3(0, 1, 0));
	//modelMatrix = glm::rotate(modelMatrix, glm::radians(th/3), glm::vec3(1, 0, 0));
	modelMatrix = glm::translate(modelMatrix, position);
	modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.x), glm::vec3(1, 0, 0));
	modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.y), glm::vec3(0, 1, 0));
	modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.z), glm::vec3(0, 0, 1));
	modelMatrix = glm::scale(modelMatrix,  glm::vec3(scale,scale,scale));
}
glm::mat4 Entity::getModelMatrix() {
	updateMatrix();
	return modelMatrix;
}
Entity::~Entity() {

}