#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW/glfw3.h>
#include <iostream>
#include <functional>
#include "Event.h"
#include "KeyEvent.h"

namespace Raiden {

	class Window {
		public:
			Window(int width, int height, std::string title);
			bool initWindow(int width, int height, std::string title);
			bool shouldClose();
			GLFWwindow *getGlfwWindow();
			void swapBuffers(); 
			void setSync(int n);
			void setEventCallback(std::function<void(Event&)> fn);
			void setWindowSize(int width, int height);
			~Window();
		private:
			GLFWwindow *window;
			struct WinStruct {
				std::string title;
				int width;
				int height;
				std::function<void(Event&)> callback;
			}data;
	};

}

#endif
