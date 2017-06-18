#pragma once

#include "glm/gtc/type_ptr.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtx/rotate_vector.hpp"

#include "GlobalConstants.h"
#include <GLFW/glfw3.h>

using namespace glm;

class Camera {
public:
	Camera();

	static void moveDown();
	static void moveForward();
	static void moveBackward();
	static void moveRight();
	static void moveLeft();
	static void moveUp();
	static void zoomIn();
	static void zoomOut();
	static void scaleNormal();
	static void rotateCamera(double xpos, double ypos);
};
