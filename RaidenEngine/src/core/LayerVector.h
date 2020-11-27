#ifndef LAYER_VECTOR_H
#define LAYER_VECTOR_H

#include "Layer.h"
#include <vector>

namespace Raiden {

	class LayerVector {
		public:
			LayerVector();
			~LayerVector();
			void pop();
			void push(Layer *layer);
			size_t getSize(); 
			std::vector<Layer *>::iterator begin(); 
			std::vector<Layer *>::iterator end(); 
		private:
			std::vector<Layer *> layerVector;	
	};

}

#endif
