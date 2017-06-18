#include "Camera.h"
#include <GL/glew.h>
#include <iostream>

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

void Camera::zoomIn() {
	scalar = 1.1f;
}

void Camera::zoomOut() {
	scalar = 1.0f / 1.1f;
}

void Camera::scaleNormal() {
	scalar = 1.0f;
}

