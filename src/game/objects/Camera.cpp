#include"Camera.h"
#include<iostream>
Camera::Camera() {
	position = new glm::vec3(0, 0.01f, 0);
	pitch = new float(0.0);
	yaw = new float(0.0);
	roll = new float(0.0);
	view = glm::mat4(1);
	shouldUpdate = true;
}
glm::mat4 Camera::getViewMatrix() {
	if (shouldUpdate) {
		view = glm::rotate(glm::mat4(1), glm::radians(*pitch), glm::vec3(1, 0, 0));
		view = glm::rotate(view, glm::radians(*yaw), glm::vec3(0, 1, 0));
		view = glm::rotate(view, glm::radians(*roll), glm::vec3(0, 0, 1));
		view = glm::translate(view, -*position);
	}shouldUpdate = false;
	return view;
}

void Camera::increasePosition(float dx, float dy, float dz) {
	position->x+=dx;
	position->y+=dy;
	position->z+=dz;

	shouldUpdate = true;
}
void Camera::increasePitch(float dp) {
	*pitch += dp;

	shouldUpdate = true;
}
void Camera::increaseYaw(float dy) {
	*yaw += dy;

	shouldUpdate = true;
}

Camera::~Camera() {
	delete yaw, pitch, roll, position;
}