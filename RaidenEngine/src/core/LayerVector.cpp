#include "LayerVector.h"

namespace Raiden {
	
	LayerVector::LayerVector() : layerVector() {

	}

	LayerVector::~LayerVector() {
		for (Layer *layer : layerVector) {
			delete layer;
		}
		layerVector.clear();
	}

	void LayerVector::push(Layer *layer) {
		layerVector.push_back(layer);
	}

	void LayerVector::pop() {
		delete layerVector[layerVector.size() - 1];
		layerVector.pop_back();
	}

	size_t LayerVector::getSize() {
		return layerVector.size();	
	}

	std::vector<Layer *>::iterator LayerVector::begin() {
		return layerVector.begin();
	}

	std::vector<Layer *>::iterator LayerVector::end() {
		return layerVector.end();
	}
}
