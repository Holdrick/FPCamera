#include "GLFWRunner.h"

void GLFWRunner::doGraphicsWork() {
	shaderObject->setupShaders(vsFilename, fsFilename);
	renderer->addGraphicsObject("floor.obj", vec3(0.0f, 0.0f, 0.0f), 1.0f);

	if (shaderObject->getShaderID()) {
		while (!glfwWindowShouldClose(window)) {
			glfwGetFramebufferSize(window, &width, &height);
			glViewport(0, 0, width, height);

			renderer->render(shaderObject->getShaderID(), shaderObject->getMVPtr(), shaderObject->getViewPtr(), shaderObject->getProjPtr(), shaderObject->getAmbientPtr(), rotMatrix, transMatrix, scalar);

			glfwSwapBuffers(window);
			glfwPollEvents();
		}
	}
}

int GLFWRunner::runGLFW() {
	if (!glfwInit()) {
		cout << "Couldn't initialize GLFW. \n";
		return 1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(width, height, "FP Camera", NULL, NULL);
	if (!window) {
		if (shaderObject->getShaderID()) {
			glDeleteProgram(shaderObject->getShaderID());
			glDeleteVertexArrays(1, &VAO);
		}
		glfwTerminate();
		return 1;
	}
	Camera::setGlfwCallbackFunctions(window);

	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if (err != GLEW_OK) {
		printf("Couldn't initialize GLEW.\n");
		return 1;
	}

	doGraphicsWork();

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
