#include "Texture.h"
#include "glad/glad.h"
#include "stb_image.h"

namespace Raiden {

	Texture::Texture() {
		unsigned int data = 0xffffffff;

		glGenTextures(1, &id);
		glBindTexture(GL_TEXTURE_2D, id);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 1, 1, 0, GL_RGBA, GL_UNSIGNED_BYTE, &data);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glGenerateMipmap(0);
	}

	Texture::Texture(std::string path) {
		int channels;
		data = stbi_load(path.c_str(), &width, &height, &channels, 0); 
		unsigned int format;

		if (channels == 3) {
			format = GL_RGB;
		} else {
			format = GL_RGBA;
		}

		glGenTextures(1, &id);
		glBindTexture(GL_TEXTURE_2D, id);
		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glGenerateMipmap(0);
	}

	void Texture::bind(Shader *shader, unsigned slots, std::string name) {
		glActiveTexture(slots + GL_TEXTURE0);	
		glBindTexture(GL_TEXTURE_2D, id);
		shader->setUniform1i(slots, name); 	
	}
	
	glm::vec2 Texture::getSize() {
		return { width, height };
	}

	float Texture::getWidth() {
		return width;
	}

	float Texture::getHeight() {
		return height;
	}

	Texture::~Texture() {
		glDeleteTextures(1, &id);
		stbi_image_free(data);
	}
}
