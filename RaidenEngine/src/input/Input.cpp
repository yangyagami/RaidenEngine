#include "Input.h"

namespace Raiden {
	
	Window *Input::window = nullptr;

	void Input::init(Window *w) {
		window = w;
	}

	bool Input::keyDown(int keycode) {
		bool v = false;
		if (glfwGetKey(window->getGlfwWindow(), keycode) == GLFW_PRESS) {
			v = true;
		}
		return v;
	}

}
