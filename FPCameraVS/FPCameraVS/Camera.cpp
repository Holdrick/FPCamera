#include "Camera.h"

void Camera::moveUp() {
	transMatrix = translate(mat4(1.0f), vec3(0.0f, -1.0f, 0.0f)) * transMatrix;
}

void Camera::moveDown() {
	transMatrix = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f)) * transMatrix;
}

void Camera::moveForward() {
	transMatrix = translate(mat4(1.0f), vec3(0.0f, 0.0f, -1.0f)) * transMatrix;
}

void Camera::moveBackward() {
	transMatrix = translate(mat4(1.0f), vec3(0.0f, 0.0f, 1.0f)) * transMatrix;
}

void Camera::moveRight() {
	transMatrix = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f)) * transMatrix;
}

void Camera::moveLeft() {
	transMatrix = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f)) * transMatrix;
}
