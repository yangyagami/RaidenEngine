#ifndef FONT_H
#define FONT_H

#include <glm/glm.hpp>
#include "Texture.h"

namespace Raiden {

	struct Character {
		Texture texture;	
		glm::ivec2 bearing;
		unsigned int advance;
	};

}

#endif

