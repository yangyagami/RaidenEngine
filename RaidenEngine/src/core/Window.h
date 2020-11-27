#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW/glfw3.h>
#include <iostream>

namespace Raiden {

	class Window {
		public:
			Window(int width, int height, std::string title);
			bool initWindow(int width, int height, std::string title);
			bool shouldClose();
			GLFWwindow *getGlfwWindow();
			void swapBuffers(); 
			void setSync(int n);
			~Window();
		private:
			GLFWwindow *window;
	};

}

#endif
