#ifndef TEXTURE_H
#define TEXTURE_H

#include "Shader.h"

namespace Raiden {

	class Texture {
		public:
			Texture();
			Texture(std::string path);
			void bind(Shader *shader, unsigned int slots, std::string name);
			glm::vec2 getSize();
			float getHeight();
			float getWidth();
			~Texture();
		private:
			unsigned int id;
			int width;
			int height;
			unsigned char *data;
	};

}

#endif
