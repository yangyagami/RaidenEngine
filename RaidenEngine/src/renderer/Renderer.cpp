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

	struct Vertex {
		glm::vec4 position;	
		glm::vec4 color;
	}*vertices, *verticesPtr;

	const unsigned int maxQuads = 10000;
	const unsigned int maxVertices = maxQuads * 4;
	const unsigned int maxIndices = maxQuads * 6;
	unsigned int *indices = nullptr;
	glm::vec4 position[4];

	void Renderer::init() {

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

		vao->setLayout(0, 4, 8 * sizeof(float), nullptr);
		vao->setLayout(1, 4, 8 * sizeof(float), (void *)(4 * sizeof(float)));

		shader = new Shader();
		shader->use();

		position[0] = { 0.0f, 0.0f, 0.0f, 1.0f };
		position[1] = { 1.0f, 0.0f, 0.0f, 1.0f };
		position[2] = { 1.0f, 1.0f, 0.0f, 1.0f };
		position[3] = { 0.0f, 1.0f, 0.0f, 1.0f };
	}

	void Renderer::begin() {
		glm::mat4 projection = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f, -1.0f, 1.0f);
		shader->setUniformMat4f(projection, "proj");

		startBatch();
	}

	void Renderer::end() {
		render();
	}

	void Renderer::drawRect(glm::vec2 pos, glm::vec2 size, glm::vec4 color) {
		if (quadsCount >= maxQuads) {
			//reBatch();
			reBatch();
		}
		glm::mat4 translate = glm::translate(glm::mat4(1.0f), glm::vec3(pos.x, pos.y, 0.0f));	
		glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(size.x, size.y, 1.0f));
		glm::mat4 transform = translate * scale;
		for (int i = 0; i < 4; i++) {
			verticesPtr->position = transform * position[i];
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
	}

	void Renderer::reBatch() {
		render();
		startBatch();
	}

	void Renderer::render() {
		if (quadsCount != 0) {
			unsigned int dataSize = verticesPtr - vertices;
			vbo->updateBuffer(dataSize * sizeof(Vertex), vertices);
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
