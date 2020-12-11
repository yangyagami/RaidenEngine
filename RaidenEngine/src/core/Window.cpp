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

	void Window::setEventCallback(std::function<void(Event&)> fn) {
		data.callback = fn;
	}

	bool Window::initWindow(int width, int height, std::string title) {
		bool v = true;

		data.width = width;
		data.height = height;
		data.title = title;

		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

		glfwMakeContextCurrent(window);

		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

		glViewport(0, 0, width, height);

		glfwSetWindowUserPointer(window, (void *)&data);

		glfwSetKeyCallback(window, [](GLFWwindow *window, int key, int scancode, int action, int mods) {
			WinStruct &data = *(WinStruct*)glfwGetWindowUserPointer(window);	

			switch (action) {
				case GLFW_PRESS:
					KeyEvent event(key);
					data.callback(event);
					break;
			}

		});

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

	void Window::setWindowSize(int width, int height) {
		glfwSetWindowSize(window, width, height);
	}

	Window::~Window() {
		glfwTerminate();
		window = nullptr;
	}

}

