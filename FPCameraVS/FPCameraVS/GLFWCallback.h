#pragma once
#include <GLFW/glfw3.h>
#include "GlobalConstants.h"
#include "Camera.h"

class GLFWCallback {
private:
	static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void mouseCallback(GLFWwindow* window, int button, int action, int mods);
	static void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos);

public:
	static void setGlfwCallbackFunctions(GLFWwindow* window);
};
