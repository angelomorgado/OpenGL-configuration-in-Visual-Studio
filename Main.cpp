#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

//Global variables
const GLint WIDTH = 800, HEIGHT = 600;

// Initial configuration of GLFW
void configureGLFW() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
}

int main() {
	configureGLFW();

	GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Learn OpenGL", nullptr, nullptr);

	int screenWidth, screenHeight;
	glfwGetFramebufferSize(window, &screenWidth, &screenHeight); 
	
	if (nullptr == window) {
		std::cout << "GLFW Failure" << std::endl;
		glfwTerminate();
		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window); 
	glewExperimental = GL_TRUE; 

	if (GLEW_OK != glewInit()) {
		std::cout << "Failure GLEW" << std::endl;
		return EXIT_FAILURE;
	}

	glViewport(0, 0, screenWidth, screenWidth); 

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents(); 

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT); 

		glfwSwapBuffers(window); 
	}

	glfwTerminate();

	return EXIT_SUCCESS;
}