#pragma once

#include "GraphicsObject.h"
#include "ShaderObject.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Renderer.h"
#include "Camera.h"

using namespace std;
using namespace glm;

class GLFWRunner {
private:
	GLuint VAO;
	GLuint shaderProgram;

	string vsFilename = "vert-phong.vs.glsl";
	string fsFilename = "frag-phong.fs.glsl";

	int width = 1200;
	int height = 900;
	static GLubyte shaderText[8192];

	GLuint mv_ptr, proj_ptr, amb_ptr;

	GLFWwindow* window;
	ShaderObject* shaderObject = new ShaderObject();
	Renderer* renderer = new Renderer();

	void doGraphicsWork();

public:

	GLFWRunner() {
	}

	int runGLFW();

};
