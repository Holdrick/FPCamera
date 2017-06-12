#include "Renderer.h"


Renderer::Renderer() {
}

void Renderer::addGraphicsObject(string filename, vec3 startPosition, GLfloat scaleFactor) {
	GraphicsObject* gobj = new GraphicsObject(startPosition, scaleFactor);
	gobj->initializeObjectInMemory(filename);

	graphicsObjects.push_back(gobj);
}

mat4 scaleMatrix = mat4(1.0f);

void Renderer::render(GLuint shaderID, GLuint modelPtr, GLuint viewPtr, GLuint projPtr, GLuint ambPtr, mat4 rot, mat4 trans, float scalar) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(shaderID);

	scaleMatrix = scale(mat4(1.0f), vec3(scalar)) * scaleMatrix;

	//Model View Matrix setup
	mat4 modelView = lookAt(vec3(0.0f, 5.0f, -10.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f));
	modelView *= rot * scaleMatrix * trans;

	glUniformMatrix4fv(modelPtr, 1, GL_FALSE, value_ptr(modelView));

	//Projection Matrix setup
	mat4 proj = perspective(45.0f, 1200.0f / 900.0f, 0.1f, 100.0f);
	glUniformMatrix4fv(projPtr, 1, GL_FALSE, value_ptr(proj));

	glUniform3f(ambPtr, 0.2f, 0.2f, 0.2f);


	for (GraphicsObject* gobj : graphicsObjects) {
		//gobj->buffer();
		gobj->draw(mat4(1.0f), modelPtr, viewPtr, projPtr, ambPtr, rot, scalar);
	}
}
