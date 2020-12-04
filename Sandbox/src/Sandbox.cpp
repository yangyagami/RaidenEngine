#include "Renderer.h"
#include "Application.h"
#include <iostream>
#include "Layer.h"
#include "Input.h"
#include <cmath>

class TestLayer : public Raiden::Layer {
	public:
		TestLayer() : picture("1.jpg") {
			pos = { 0.0f, 0.0f };
			size = { 800.0f, 600.0f };
			color = { 1.0f, 0.5f, 0.5f, 1.0f };
		}
	
		virtual void update(float dt) {
			Raiden::Renderer::begin();	
			{
				
				Raiden::Renderer::clearColor(0.5f, 0.5f, 0.5f, 1.0f);
				Raiden::Renderer::drawTexture(picture, pos, size, color);
			}
			Raiden::Renderer::end();	
		}
	
		virtual ~TestLayer() {
	
		}
	private:
		glm::vec2 pos;
		glm::vec2 size;
		glm::vec4 color;
		Raiden::Texture picture;
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
