#include <stb_image.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void process_input(GLFWwindow* window);

const unsigned int SCR_WIDTH = 1366;
const unsigned int SCR_HEIGHT = 768;

int main() {

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Basic Window", nullptr, nullptr);

	// Change the default Application Icon
	int appImageWidth, appImageHeight;
	int appImageChannels;
	unsigned char* appImagePixels = stbi_load("./assets/GhoststarFINISHED.png", &appImageWidth, &appImageHeight, &appImageChannels, 4);

	GLFWimage images[1];
	images[0].width = appImageWidth;
	images[0].height = appImageHeight;
	images[0].pixels = appImagePixels;

	glfwSetWindowIcon(window, 1, images);

	if (window == nullptr) {
		std::cout << "Failed to create " << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to Load GL Loader" << std::endl;
		return -1;
	}

	glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);

	glClearColor(.2f, .3f, .3f, 1.0f);

	while (!glfwWindowShouldClose(window)) {

		process_input(window);


		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();

	}

	glfwTerminate();


}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

void process_input(GLFWwindow* window) {

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

}