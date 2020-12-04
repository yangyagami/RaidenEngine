#ifndef SHADER_H
#define SHADER_H

#include "glad/glad.h"
#include <iostream>
#include <glm/glm.hpp>

namespace Raiden {
	
	class Shader {
		public:
			Shader();
			~Shader();
			void use();
			unsigned int getShaderID();
			void setUniformMat4f(glm::mat4 matrix, std::string name);
			void setUniform1i(unsigned int n, std::string name);
		private:
			void createShaderProgram();
			unsigned int createShader(GLenum shaderType, std::string shaderSrc);
		private:
			unsigned int id;
	};

}

#endif
