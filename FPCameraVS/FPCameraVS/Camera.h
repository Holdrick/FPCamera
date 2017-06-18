#pragma once

#include "glm/gtc/type_ptr.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "GlobalConstants.h"
#include <GLFW/glfw3.h>

using namespace glm;

class Camera {
private:
public:
	static void moveDown();
	static void moveForward();
	static void moveBackward();
	static void moveRight();
	static void moveLeft();
	static void moveUp();

	static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void mouseCallback(GLFWwindow* window, int button, int action, int mods);
	static void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos);
	static void setGlfwCallbackFunctions(GLFWwindow* window);
};
