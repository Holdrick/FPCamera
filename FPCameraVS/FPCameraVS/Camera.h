#pragma once

#include "glm/gtc/type_ptr.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "GlobalConstants.h"

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
};
