#ifndef TEXT_H
#define TEXT_H

#include <iostream>
#include <glm/glm.hpp>
#include <Texture.h>

namespace Raiden {

	class Text {
		public:
			Text(std::string text);
			int getWidth();
			int getHeight();
			glm::ivec2 getSize();
			~Text();
		private:
			std::string mText;
			int mWidth;
			int mHeight;
	};

}

#endif
