#include "Shader.h"
#include <glm/gtc/type_ptr.hpp>

namespace Raiden {

	Shader::Shader() {
		createShaderProgram();
	}

	Shader::~Shader() {
		glUseProgram(0);
		glDeleteProgram(id);
	}

	void Shader::use() {
		glUseProgram(id);
	}

	void Shader::createShaderProgram() {
		std::string vertexShaderSrc = R"(
			#version 330 core
			layout (location = 0) in vec4 aPos;
			layout (location = 1) in vec4 aColor;
			out vec4 mColor;
			uniform mat4 proj;
			void main() {
				gl_Position = proj * aPos;
				mColor = aColor;
			}
		)";

		std::string fragmentShaderSrc = R"(
			#version 330 core
			out vec4 fragColor;
			in vec4 mColor;
			void main() {
				fragColor = mColor;
			}
		)";
		int success;
		char infoLog[512];
		unsigned int vertexShader = createShader(GL_VERTEX_SHADER, vertexShaderSrc); 
		unsigned int fragmentShader = createShader(GL_FRAGMENT_SHADER, fragmentShaderSrc); 

		id = glCreateProgram();
		glAttachShader(id, vertexShader);
		glAttachShader(id, fragmentShader);
		glLinkProgram(id);

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

		glGetProgramiv(id, GL_LINK_STATUS, &success);

		if (!success) {
			glGetProgramInfoLog(id, 512, nullptr, infoLog);
			std::cout << "PROGRAM ERROR: " << infoLog << std::endl;
		}
	}

	unsigned int Shader::createShader(GLenum shaderType, std::string shaderSrc) {
		unsigned int shader;
		int success;
		const char *src = shaderSrc.c_str();
		char infoLog[512];

		shader = glCreateShader(shaderType);
		glShaderSource(shader, 1, &src, nullptr);
		glCompileShader(shader);
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

		if (!success) {
			glGetShaderInfoLog(shader, 512, nullptr, infoLog);
			std::cout << (shaderType == GL_VERTEX_SHADER ? "VERTEX SHADER ERROR: " : "FRAGMENT SHADER ERROR: ")<< infoLog << std::endl;
		}

		return shader;
	}

	unsigned int Shader::getShaderID() {
		return id;
	}

	void Shader::setUniformMat4f(glm::mat4 matrix, std::string name) {
		int location = glGetUniformLocation(id, name.c_str());
		glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
	}

}
