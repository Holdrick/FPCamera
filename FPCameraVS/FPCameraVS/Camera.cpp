#include "Camera.h"
#include <GL/glew.h>
#include <iostream>

void Camera::moveUp() {
	cameraEye.y += 0.1f;
	cameraView.y += 0.1f;
}

void Camera::moveDown() {
	cameraEye.y -= 0.1f;
	cameraView.y -= 0.1f;
}

void Camera::moveForward() {
	cameraEye.z += 0.1f;
	cameraView.z += 0.1f;
}

void Camera::moveBackward() {
	cameraEye.z -= 0.1f;
	cameraView.z -= 0.1f;
}

void Camera::moveRight() {
	cameraEye.x -= 0.1f;
	cameraView.x -= 0.1f;
}

void Camera::moveLeft() {
	cameraEye.x += 0.1f;
	cameraView.x += 0.1f;
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

void Camera::rotateCamera(double xpos, double ypos) {
//	vec2 endPosition = glm::normalize(vec2(xpos, ypos) - vec2(0.0f));
//	vec2 startPos = glm::normalize(startPosition - vec2(0.0f));
//	float angle = glm::acos(glm::dot(startPos, endPosition));

//	vec3 axisOfRotation = vec3(1.0f);
//
//	if (endPosition.y > startPos.y)
//		axisOfRotation = vec3(0.0f, 1.0f, 0.0f);
//	else
//		axisOfRotation = vec3(0.0f, -1.0f, 0.0f);

	//rotMatrix = rotate(cameraEye, 0.5f, cameraView) * rotMatrix;
	cameraView = glm::rotate(cameraView, 0.5f, cameraEye);


	/*	if (key == GLFW_KEY_UP && (action == GLFW_PRESS || action == GLFW_REPEAT))
	rotMatrix = rotate(mat4(1.0f), 0.5f, vec3(1.0f, 0.0f, 0.0f)) * rotMatrix;
	if (key == GLFW_KEY_DOWN && (action == GLFW_PRESS || action == GLFW_REPEAT))
	rotMatrix = rotate(mat4(1.0f), 0.5f, vec3(-1.0f, 0.0f, 0.0f)) * rotMatrix;

	if (key == GLFW_KEY_RIGHT && (action == GLFW_PRESS || action == GLFW_REPEAT))
	rotMatrix = rotate(mat4(1.0f), 0.5f, vec3(0.0f, 1.0f, 0.0f)) * rotMatrix;
	if (key == GLFW_KEY_LEFT && (action == GLFW_PRESS || action == GLFW_REPEAT))
	rotMatrix = rotate(mat4(1.0f), 0.5f, vec3(0.0f, -1.0f, 0.0f)) * rotMatrix;*/
}


