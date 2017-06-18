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

void Camera::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (key == GLFW_KEY_Q && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

	if (key == GLFW_KEY_SPACE && (action == GLFW_PRESS || action == GLFW_REPEAT))
		Camera::moveUp();
	if (key == GLFW_KEY_LEFT_SHIFT && (action == GLFW_PRESS || action == GLFW_REPEAT))
		Camera::moveDown();

	if (key == GLFW_KEY_W && (action == GLFW_PRESS || action == GLFW_REPEAT))
		Camera::moveForward();
	if (key == GLFW_KEY_S && (action == GLFW_PRESS || action == GLFW_REPEAT))
		Camera::moveBackward();

	if (key == GLFW_KEY_D && (action == GLFW_PRESS || action == GLFW_REPEAT))
		Camera::moveRight();
	if (key == GLFW_KEY_A && (action == GLFW_PRESS || action == GLFW_REPEAT))
		Camera::moveLeft();

	if (key == GLFW_KEY_PAGE_UP && action == GLFW_PRESS)
		scalar = 1.1f;
	if (key == GLFW_KEY_PAGE_UP && action == GLFW_RELEASE)
		scalar = 1.0f;

	if (key == GLFW_KEY_PAGE_DOWN && action == GLFW_PRESS)
		scalar = 1.0f / 1.1f;
	if (key == GLFW_KEY_PAGE_DOWN && action == GLFW_RELEASE)
		scalar = 1.0f;

	/*	if (key == GLFW_KEY_UP && (action == GLFW_PRESS || action == GLFW_REPEAT))
	rotMatrix = rotate(mat4(1.0f), 0.5f, vec3(1.0f, 0.0f, 0.0f)) * rotMatrix;
	if (key == GLFW_KEY_DOWN && (action == GLFW_PRESS || action == GLFW_REPEAT))
	rotMatrix = rotate(mat4(1.0f), 0.5f, vec3(-1.0f, 0.0f, 0.0f)) * rotMatrix;

	if (key == GLFW_KEY_RIGHT && (action == GLFW_PRESS || action == GLFW_REPEAT))
	rotMatrix = rotate(mat4(1.0f), 0.5f, vec3(0.0f, 1.0f, 0.0f)) * rotMatrix;
	if (key == GLFW_KEY_LEFT && (action == GLFW_PRESS || action == GLFW_REPEAT))
	rotMatrix = rotate(mat4(1.0f), 0.5f, vec3(0.0f, -1.0f, 0.0f)) * rotMatrix;*/
}


void Camera::mouseCallback(GLFWwindow* window, int button, int action, int mods) {
	double xpos, ypos;

	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS){
		rightClickPressed = true;
		glfwGetCursorPos(window, &xpos, &ypos);
		startPosition = vec2(xpos, ypos);
	}
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE){
		rightClickPressed = false;
		glfwGetCursorPos(window, &xpos, &ypos);
		endPosition = vec2(xpos, ypos);
	}
	std::cout << startPosition.x << " " << startPosition.y << std::endl;
	std::cout << endPosition.x << " " << endPosition.y << std::endl;
}

void Camera::cursorPositionCallback(GLFWwindow* window, double xpos, double ypos) {
}

void Camera::setGlfwCallbackFunctions(GLFWwindow* window) {
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, keyCallback);
	glfwSetMouseButtonCallback(window, mouseCallback);
	glfwSetCursorPosCallback(window, cursorPositionCallback);
}
