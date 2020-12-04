#ifndef LAYER_H
#define LAYER_H

namespace Raiden {

	class Layer {
		public:
			Layer();
			virtual void update(float dt) = 0;
			virtual ~Layer();
	};

}

#endif
