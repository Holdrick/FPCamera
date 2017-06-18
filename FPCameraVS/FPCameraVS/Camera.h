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
	static void zoomIn();
	static void zoomOut();
	static void scaleNormal();
};
