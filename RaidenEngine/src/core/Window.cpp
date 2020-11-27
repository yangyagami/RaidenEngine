#include "glad/glad.h"
#include "Window.h"

namespace Raiden {

	Window::Window(int width, int height, std::string title) : window(nullptr) {
		if (!initWindow(width, height, title)) {
			std::cout << "init window failed" << std::endl;	
		}
	}

	void Window::setSync(int n) {
		glfwSwapInterval(n);
	}

	bool Window::initWindow(int width, int height, std::string title) {
		bool v = true;
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

		glfwMakeContextCurrent(window);

		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

		glViewport(0, 0, width, height);

		return v;
	}

	bool Window::shouldClose() {
		return glfwWindowShouldClose(window);
	}

	GLFWwindow *Window::getGlfwWindow() {
		return window;
	}

	void Window::swapBuffers() {
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	Window::~Window() {
		glfwTerminate();
		window = nullptr;
	}

}

