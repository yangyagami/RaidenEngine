#include <iostream>
#include "Renderer.h"
#include "Application.h"

namespace Raiden {

	Application::Application() : exit(false), layerVector(), startTime(0.0f), finishTime(0.0f), dt(0.0f) {
		window = new Window(800, 600, "RaidenEngine");
		std::cout << "Create Application" << std::endl;	
		Renderer::init();
		window->setSync(1);
	}
	
	Application::~Application() {
		Renderer::shutdown();
		delete window;
		std::cout << "Shutdown Application" << std::endl;	
	}

	void Application::run() {
		while(!exit) {
			finishTime = (float)glfwGetTime();
			dt = finishTime - startTime;
			startTime = finishTime;

			if (window->shouldClose()) {
				exit = true;
			}

			Renderer::clear();

			if (layerVector.getSize() == 0) {
				Renderer::clearColor(0.3f, 0.3f, 0.3f, 1.0f);
			} else {
				for (Layer *layer : layerVector) {
					layer->update();
				}
			}

			window->swapBuffers();

			std::cout << 1.0f / dt << std::endl;
		}
	}

	void Application::pushLayer(Layer *layer) {
		layerVector.push(layer);
	}
}
