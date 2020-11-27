#ifndef BUFFER_H
#define BUFFER_H

#include "glad/glad.h"

namespace Raiden {

	class Buffer {
		public:
			Buffer(GLsizeiptr size, GLenum type);
			Buffer(const void *data, GLsizeiptr size, GLenum type);
			~Buffer();
			void bind();
			void updateBuffer(GLsizeiptr size, const void *data);
		private:
			unsigned int id;
			GLenum mType;
	};

}

#endif
