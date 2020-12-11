#ifndef LAYER_H
#define LAYER_H

#include "Event.h"

namespace Raiden {

	class Layer {
		public:
			Layer();
			virtual void update(float dt) = 0;
			virtual void draw(float dt = 0.0f) = 0;
			virtual void onEvent(Event &e) = 0;
			virtual ~Layer();
	};

}

#endif
