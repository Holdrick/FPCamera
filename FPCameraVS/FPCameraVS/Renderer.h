﻿#pragma once
#include "GraphicsObject.h"
#include "GlobalConstants.h"

class Renderer {
private:
	vector<GraphicsObject*> graphicsObjects;
public:

	Renderer();

	void addGraphicsObject(string filename, vec3 startPosition, GLfloat scaleFactor);
	void render(GLuint shaderID, GLuint mvPtr, GLuint viewPtr, GLuint projPtr, GLuint ambPtr, mat4 rot, mat4 trans, float scale);
};
