#include "Renderer.h"
#include "Application.h"
#include <iostream>
#include "Layer.h"
#include "Input.h"
#include <cmath>

class Test : public Raiden::Layer {
	public:
		Test(int width, int height) : WINDOW_WIDTH(width), WINDOW_HEIGHT(height) {

		}
		virtual void update(float dt) override {

		}
		virtual void draw(float dt = 0.0f) override {
			Raiden::Renderer::begin();
			{
				glm::vec2 pos(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
				glm::vec2 size(30.0f, 30.0f);
				glm::vec4 color(1.0f, 0.5f, 1.0f, 1.0f);

				Raiden::Renderer::drawRect(pos, size, color);
			}
			Raiden::Renderer::end();
		}
		virtual void onEvent(Raiden::Event &e) override {

		}
		~Test() {

		}
	private:
		const int WINDOW_WIDTH;
		const int WINDOW_HEIGHT;
};

class Sandbox : public Raiden::Application {
	public:
		Sandbox() {
			Test *layer = new Test(WINDOW_WIDTH, WINDOW_HEIGHT);
			pushLayer(layer);

			setWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
		}
		virtual ~Sandbox() {
			std::cout << "shutdown sandbox" << std::endl;	
		}
	private:
		const int WINDOW_HEIGHT = 300;
		const int WINDOW_WIDTH = 400;
};

Raiden::Application *Raiden::createApplication() {
	Sandbox *app = new Sandbox();
	return app;
}
