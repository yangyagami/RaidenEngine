#include "VertexArray.h"

namespace Raiden {

	VertexArray::VertexArray() {
		glGenVertexArrays(1, &id);
		bind();
	}

	void VertexArray::bind() {
		glBindVertexArray(id);
	}

	void VertexArray::setLayout(unsigned int index, int vecN, GLsizei stride, const void *pointer) {
		glVertexAttribPointer(index, vecN, GL_FLOAT, GL_FALSE, stride, pointer);
		glEnableVertexAttribArray(index);
	}

	VertexArray::~VertexArray() {
		glBindVertexArray(0);
		glDeleteVertexArrays(1, &id);
	}

}
