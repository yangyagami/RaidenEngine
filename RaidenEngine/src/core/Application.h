#ifndef APPLICATION_H
#define APPLICATION_H

#include "Window.h"
#include "LayerVector.h"
#include "KeyEvent.h"

namespace Raiden {

	class Application {
		public:
			Application();
			virtual ~Application();
			void run();
			void onEvent(Event &e);
			void setWindowSize(int width, int height);
			void pushLayer(Layer *layer);
		private:
			LayerVector layerVector;
			bool exit;
			Window *window;
			float startTime;
			float finishTime;
			float dt;
	};
	
	Application *createApplication(); 
}

#endif

