#include "GLFWRunner.h"

// Transformation matrices
extern mat4 rotMatrix = mat4(1.0f);
extern mat4 transMatrix = mat4(1.0f);
extern float scalar = 1.0f;

void GLFWRunner::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

	if (key == GLFW_KEY_SPACE && (action == GLFW_PRESS || action == GLFW_REPEAT))
		transMatrix = translate(mat4(1.0f), vec3(0.0f, -1.0f, 0.0f)) * transMatrix;
	if (key == GLFW_KEY_LEFT_SHIFT && (action == GLFW_PRESS || action == GLFW_REPEAT))
		transMatrix = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f)) * transMatrix;

	if (key == GLFW_KEY_UP && (action == GLFW_PRESS || action == GLFW_REPEAT))
		transMatrix = translate(mat4(1.0f), vec3(0.0f, 0.0f, -1.0f)) * transMatrix;
	if (key == GLFW_KEY_DOWN && (action == GLFW_PRESS || action == GLFW_REPEAT))
		transMatrix = translate(mat4(1.0f), vec3(0.0f, 0.0f, 1.0f)) * transMatrix;

	if (key == GLFW_KEY_RIGHT && (action == GLFW_PRESS || action == GLFW_REPEAT))
		transMatrix = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f)) * transMatrix;
	if (key == GLFW_KEY_LEFT && (action == GLFW_PRESS || action == GLFW_REPEAT))
		transMatrix = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f)) * transMatrix;

	/*	if (key == GLFW_KEY_UP && (action == GLFW_PRESS || action == GLFW_REPEAT))
			rotMatrix = rotate(mat4(1.0f), 0.5f, vec3(1.0f, 0.0f, 0.0f)) * rotMatrix;
		if (key == GLFW_KEY_DOWN && (action == GLFW_PRESS || action == GLFW_REPEAT))
			rotMatrix = rotate(mat4(1.0f), 0.5f, vec3(-1.0f, 0.0f, 0.0f)) * rotMatrix;
	
		if (key == GLFW_KEY_RIGHT && (action == GLFW_PRESS || action == GLFW_REPEAT))
			rotMatrix = rotate(mat4(1.0f), 0.5f, vec3(0.0f, 1.0f, 0.0f)) * rotMatrix;
		if (key == GLFW_KEY_LEFT && (action == GLFW_PRESS || action == GLFW_REPEAT))
			rotMatrix = rotate(mat4(1.0f), 0.5f, vec3(0.0f, -1.0f, 0.0f)) * rotMatrix;*/
}


void GLFWRunner::mouse_callback(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
		scalar = 1.1f;
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
		scalar = 1.0f;

	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
		scalar = 1.0f / 1.1f;
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE)
		scalar = 1.0f;
}

void GLFWRunner::doGraphicsWork()
{
	shaderObject->setupShaders(vsFilename, fsFilename);
	renderer->addGraphicsObject("floor.obj", vec3(0.0f, 0.0f, 0.0f), 1.0f);

	if (shaderObject->getShaderID())
	{
		while (!glfwWindowShouldClose(window))
		{
			glfwGetFramebufferSize(window, &width, &height);
			glViewport(0, 0, width, height);

			renderer->render(shaderObject->getShaderID(), shaderObject->getMVPtr(), shaderObject->getViewPtr(), shaderObject->getProjPtr(), shaderObject->getAmbientPtr(), rotMatrix, transMatrix, scalar);

			glfwSwapBuffers(window);
			glfwPollEvents();
		}
	}
}

int GLFWRunner::runGLFW()
{
	if (!glfwInit())
	{
		cout << "Couldn't initialize GLFW. \n";
		return 1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(width, height, "FP Camera", NULL, NULL);
	if (!window)
	{
		if (shaderObject->getShaderID())
		{
			glDeleteProgram(shaderObject->getShaderID());
			glDeleteVertexArrays(1, &VAO);
		}
		glfwTerminate();
		return 1;
	}
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, key_callback);
	glfwSetMouseButtonCallback(window, mouse_callback);

	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if (err != GLEW_OK)
	{
		printf("Couldn't initialize GLEW.\n");
		return 1;
	}

	doGraphicsWork();

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
