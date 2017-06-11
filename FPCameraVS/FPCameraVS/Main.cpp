#include "GLFWRunner.h"

int main(int argc, char **argv){
	GLFWRunner* glfwRunner = new GLFWRunner();
	return glfwRunner->runGLFW();
}
