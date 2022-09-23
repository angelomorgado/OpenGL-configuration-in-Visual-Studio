// OpenGL program template - It creates a basic window 
#include <iostream>

//#define GLEW_STATIC // If glew is static uncomment

#include <GL/glew.h>
#include <GLFW/glfw3.h>

//Windows prop
const GLint WIDTH = 800, HEIGHT = 600;

int main() {
	glfwInit();

	// GLFW version range
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // CORE uses the new opengl functions while COMPAR uses older opengl functions
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // Enables forwards compatibility
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE); // Resisable window?

	// Window settings
	GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Learn OpenGL", nullptr, nullptr);

	int screenWidth, screenHeight;
	glfwGetFramebufferSize(window, &screenWidth, &screenHeight); // Updates the values of width and height, the actual ones
	
	// In case GLFW fails
	if (nullptr == window) {
		std::cout << "GLFW Failure" << std::endl;
		glfwTerminate();
		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window); // Which window glfw will render
	glewExperimental = GL_TRUE; // Enables GLEW experimental features (Modern GLEW features)

	// In case GLEW fails
	if (GLEW_OK != glewInit()) {
		std::cout << "Failure GLEW" << std::endl;
		return EXIT_FAILURE;
	}

	// Initial coordinates setting
	glViewport(0, 0, screenWidth, screenWidth); 

	// Window main loop
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents(); // Checks if any events are triggered (kb or mouse events) and updates the window accordingly

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT); // Mandatory because the frame needs to be cleared before drawing the next one

		glfwSwapBuffers(window); // Swaps the front and back buffer
	}

	glfwTerminate();

	return EXIT_SUCCESS;
}
