#include "Renderer.h"
#include "glad/glad.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Raiden {

    Shader *Renderer::shader = nullptr;
	Buffer *Renderer::vbo = nullptr;
	Buffer *Renderer::ibo = nullptr;
	VertexArray *Renderer::vao = nullptr;
	unsigned int Renderer::quadsCount = 0;
	Texture *Renderer::textureSlots[10];
	std::string Renderer::textureName[10];

	struct Vertex {
		glm::vec4 position;	
		glm::vec2 texCoord;
		glm::vec4 color;
		float texIndex;
	}*vertices, *verticesPtr;

	const unsigned int maxQuads = 10000;
	const unsigned int maxVertices = maxQuads * 4;
	const unsigned int maxIndices = maxQuads * 6;
	unsigned int *indices = nullptr;
	glm::vec4 position[4];
	glm::vec2 texCoordPos[4];
	unsigned int maxSlots = 10;
	unsigned int textureSlotsIndex = 0;

	void Renderer::init() {
		textureName[0] = "mTexture0";
		textureName[1] = "mTexture1";
		textureName[2] = "mTexture2";
		textureName[3] = "mTexture3";
		textureName[4] = "mTexture4";
		textureName[5] = "mTexture5";
		textureName[6] = "mTexture6";
		textureName[7] = "mTexture7";
		textureName[8] = "mTexture8";
		textureName[9] = "mTexture9";

		vertices = new Vertex[maxVertices];
		indices = new unsigned int[maxIndices];

		verticesPtr = vertices;

		unsigned int offset = 0;

		for (int i = 0; i < maxIndices; i += 6) {
			indices[i + 0] = 0 + offset;
			indices[i + 1] = 1 + offset;
			indices[i + 2] = 2 + offset;

			indices[i + 3] = 2 + offset;
			indices[i + 4] = 3 + offset;
			indices[i + 5] = 0 + offset;

			offset += 4;
		}

		vao = new VertexArray();
		vao->bind();

		vbo = new Buffer(maxVertices * sizeof(Vertex), GL_ARRAY_BUFFER);
		vbo->bind();

		ibo = new Buffer(indices, maxIndices * sizeof(unsigned int), GL_ELEMENT_ARRAY_BUFFER);
		ibo->bind();

		vao->setLayout(0, 4, 11 * sizeof(float), nullptr);
		vao->setLayout(1, 2, 11 * sizeof(float), (void *)(4 * sizeof(float)));
		vao->setLayout(2, 4, 11 * sizeof(float), (void *)(6 * sizeof(float)));
		vao->setLayout(3, 1, 11 * sizeof(float), (void *)(10 * sizeof(float)));

		shader = new Shader();
		shader->use();

		position[0] = { 0.0f, 0.0f, 0.0f, 1.0f };
		position[1] = { 1.0f, 0.0f, 0.0f, 1.0f };
		position[2] = { 1.0f, 1.0f, 0.0f, 1.0f };
		position[3] = { 0.0f, 1.0f, 0.0f, 1.0f };

		texCoordPos[0] = { 0.0f, 1.0f };
		texCoordPos[1] = { 1.0f, 1.0f };
		texCoordPos[2] = { 1.0f, 0.0f };
		texCoordPos[3] = { 0.0f, 0.0f };

		textureSlots[0] = new Texture();
		textureSlotsIndex = 1;
	}

	void Renderer::begin() {
		glm::mat4 projection = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f, -1.0f, 1.0f);
		shader->setUniformMat4f(projection, "proj");

		startBatch();
	}

	void Renderer::end() {
		render();
	}

	void Renderer::drawRect(glm::vec2 &pos, glm::vec2 &size, glm::vec4 &color) {
		drawTexture(*textureSlots[0], pos, size, color);
	}

	void Renderer::drawTexture(Texture &texture, glm::vec2 &pos, glm::vec2 &size) {
		glm::vec4 color = { 1.0f, 1.0f, 1.0f, 1.0f };
		drawTexture(texture, pos, size, color);
	}

	void Renderer::drawTexture(Texture &texture, glm::vec2 &pos, glm::vec2 &size, glm::vec4 &color) {
		float index = -1.0f;

		if (quadsCount >= maxQuads) {
			//reBatch();
			reBatch();
		}

		glm::mat4 translate = glm::translate(glm::mat4(1.0f), glm::vec3(pos.x, pos.y, 0.0f));	
		glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(size.x, size.y, 1.0f));
		glm::mat4 transform = translate * scale;

		if (textureSlotsIndex >= maxSlots) {
			reBatch();
		}

		for (unsigned int i = 0; i < maxSlots; i++) {
			if (textureSlots[i] && textureSlots[i] == &texture) {
				index = (float)i;
				break;
			}
		}

		if (index == -1.0f) {
			textureSlots[textureSlotsIndex] = &texture;
			index = (float)textureSlotsIndex;
			textureSlotsIndex++;
		}
			
		for (int i = 0; i < 4; i++) {
			verticesPtr->position = transform * position[i];
			verticesPtr->texCoord = texCoordPos[i];
			verticesPtr->texIndex = index;
			verticesPtr->color = color;
			verticesPtr++;
		}

		quadsCount++;
	}

	void Renderer::clear() {
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void Renderer::startBatch() {
		verticesPtr = vertices;	
		quadsCount = 0;
		textureSlotsIndex = 1;
	}

	void Renderer::reBatch() {
		render();
		startBatch();
	}

	void Renderer::render() {
		if (quadsCount != 0) {
			unsigned int dataSize = verticesPtr - vertices;
			vbo->updateBuffer(dataSize * sizeof(Vertex), vertices);

			for (unsigned int i = 0; i < textureSlotsIndex; i++) {
				textureSlots[i]->bind(shader, i, textureName[i]);
			}

			glDrawElements(GL_TRIANGLES, quadsCount * 6, GL_UNSIGNED_INT, nullptr);
		}
	}

	void Renderer::clearColor(float r, float g, float b, float a) {
		glClearColor(r, g, b, a);
	}

	void Renderer::shutdown() {
		delete vbo;
		delete shader;
		delete vao;
		delete ibo;
		delete[] vertices;
		delete[] indices;
	}
}
