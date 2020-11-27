#include "Renderer.h"
#include "Application.h"
#include <iostream>
#include "Layer.h"

class TestLayer : public Raiden::Layer {
	public:
		TestLayer() {
		
		}

		virtual void update() {

			Raiden::Renderer::begin(); 
			{
				Raiden::Renderer::clearColor(0.5f, 0.5f, 0.5f, 1.0f);
				for (int i = 0; i < 100; i++) {
					for (int j = 0; j < 100; j++) {
						glm::vec2 pos(i * 31.0f, j * 31.0f);
						glm::vec2 size(30.0f, 30.0f);
						glm::vec4 color(1.0f, 0.5f, 0.5f, 1.0f);
						Raiden::Renderer::drawRect(pos, size, color);
					}
				}
			}
			Raiden::Renderer::end();
		}

		virtual ~TestLayer() {
			std::cout << "destructor" << std::endl;
		}
};

class Sandbox : public Raiden::Application {
	public:
		Sandbox() {
			TestLayer *layer = new TestLayer();
			pushLayer(layer);
		}
		virtual ~Sandbox() {
			std::cout << "shutdown sandbox" << std::endl;	
		}
};

Raiden::Application *Raiden::createApplication() {
	Sandbox *app = new Sandbox();
	return app;
}
