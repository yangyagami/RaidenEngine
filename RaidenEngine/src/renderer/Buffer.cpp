#include "Buffer.h"

namespace Raiden {

	Buffer::Buffer(GLsizeiptr size, GLenum type) : mType(type) {
		glGenBuffers(1, &id);
		bind();
		glBufferData(type, size, nullptr, GL_DYNAMIC_DRAW);
	}

	Buffer::Buffer(const void *data, GLsizeiptr size, GLenum type) : mType(type) {
		glGenBuffers(1, &id);
		bind();
		glBufferData(type, size, data, GL_STATIC_DRAW);
	}

	void Buffer::bind() {
		glBindBuffer(mType, id);
	}

	void Buffer::updateBuffer(GLsizeiptr size, const void *data) {
		bind();
		glBufferSubData(mType, 0, size, data);   
	}

	Buffer::~Buffer() {
		glBindBuffer(mType, 0);
		glDeleteBuffers(1, &id);
	}

}
