#ifndef TEXTURE_H
#define TEXTURE_H

#include "Shader.h"

namespace Raiden {

	class Texture {
		public:
			Texture();
			Texture(std::string path);
			void bind(Shader *shader, unsigned int slots, std::string name);
			~Texture();
		private:
			unsigned int id;
			unsigned int width;
			unsigned int height;
			unsigned char *data;
	};

}

#endif
