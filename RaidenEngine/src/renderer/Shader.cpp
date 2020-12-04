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
			layout (location = 1) in vec2 aTexCoord;
			layout (location = 2) in vec4 aColor;
			layout (location = 3) in float aTexIndex;
			out vec4 mColor;
			out float mTexIndex;
			out vec2 mTexCoord;
			uniform mat4 proj;
			void main() {
				gl_Position = proj * aPos;
				mColor = aColor;
				mTexIndex = aTexIndex;
				mTexCoord = aTexCoord;
			}
		)";

		std::string fragmentShaderSrc = R"(
			#version 330 core
			out vec4 fragColor;
			in float mTexIndex;
			in vec4 mColor;
			in vec2 mTexCoord;

			uniform sampler2D mTexture0;
			uniform sampler2D mTexture1;
			uniform sampler2D mTexture2;
			uniform sampler2D mTexture3;
			uniform sampler2D mTexture4;
			uniform sampler2D mTexture5;
			uniform sampler2D mTexture6;
			uniform sampler2D mTexture7;
			uniform sampler2D mTexture8;
			uniform sampler2D mTexture9;

			void main() {
				switch(int(mTexIndex)) {
					case 0:
						fragColor = texture(mTexture0, mTexCoord) * mColor;
						break;
					case 1:
						fragColor = texture(mTexture1, mTexCoord) * mColor;
						break;
					case 2:
						fragColor = texture(mTexture2, mTexCoord) * mColor;
						break;
					case 3:
						fragColor = texture(mTexture3, mTexCoord) * mColor;
						break;
					case 4:
						fragColor = texture(mTexture4, mTexCoord) * mColor;
						break;
					case 5:
						fragColor = texture(mTexture5, mTexCoord) * mColor;
						break;
					case 6:
						fragColor = texture(mTexture6, mTexCoord) * mColor;
						break;
					case 7:
						fragColor = texture(mTexture7, mTexCoord) * mColor;
						break;
					case 8:
						fragColor = texture(mTexture8, mTexCoord) * mColor;
						break;
					case 9:
						fragColor = texture(mTexture9, mTexCoord) * mColor;
						break;
				}
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

	void Shader::setUniform1i(unsigned int n, std::string name) {
		int location = glGetUniformLocation(id, name.c_str());
		glUniform1i(location, n);
	}
}
