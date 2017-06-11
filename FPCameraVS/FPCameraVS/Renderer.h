#pragma once
#include "GraphicsObject.h"
#include <list>

class Renderer
{
private:
	vector<GraphicsObject*> graphicsObjects;
public:

	Renderer();

	void addGraphicsObject(string filename, vec3 startPosition, GLfloat scaleFactor);
	void render(GLuint shaderID, GLuint mvPtr, GLuint viewPtr, GLuint projPtr, GLuint ambPtr, mat4 rot, float scale);
};
