#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H

#include "glad/glad.h"

namespace Raiden {

	class VertexArray {
		public:
			VertexArray();
			~VertexArray();
			void bind();
			void setLayout(unsigned int index, int vecN, GLsizei stride, const void *pointer);
		private:
			unsigned int id;
	};

}

#endif
