#pragma once

#include "GL/glew.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtx/transform.hpp"
#include "glm/gtc/quaternion.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
using namespace glm;


class GraphicsObject {
public:
	GraphicsObject(vec3 position, GLfloat scaleFactor);

	void readObj(string filename);
	void initializeObjectInMemory(string filename);
	void rearrangeData();
	void buffer();
	GLuint bufferSize();
	GLfloat* getData(GLuint type);
	GLuint getSize(GLuint type);
	vec3 findMax();
	vec3 findMin();
	void findCenter();
	void findDiameter();
	void draw(mat4 view, GLuint modelPtr, GLuint viewPtr, GLuint projPtr, GLuint ambPtr, mat4 rot, float scale);
	void draw(vec3 ambient, GLuint amb);


	vector<GLuint> indices, normIndices, texIndices;
	vector<GLfloat> vertices, normals, texVertices;
	vec3 center;

	void setPosition(vec3 position) { this->position = position; }
	vec3 getPosition() { return position; }

	void setScaleFactor(GLfloat scaleFactor) { this->scaleFactor = scaleFactor; }
	GLfloat getScaleFactor() { return scaleFactor; }

	void setDiameter(GLfloat diameter) { this->diameter = diameter; }
	GLfloat getDiameter() { return diameter; }
private:
	GLuint VAO, VBO;
	vec3 position;
	GLfloat scaleFactor, diameter;
};
