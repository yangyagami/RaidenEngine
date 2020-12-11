#ifndef RENDERER_H
#define RENDERER_H

#include "Shader.h"
#include "Buffer.h"
#include "VertexArray.h"
#include <glm/glm.hpp>
#include "Texture.h"

namespace Raiden {

	class Renderer {
		public:
			static void init();
			static void initFont();
			static void shutdown();
			static void begin();
			static void drawRect(glm::vec2 &pos, glm::vec2 &size, glm::vec4 &color);
			static void drawTexture(Texture &texture, glm::vec2 &pos, glm::vec2 &size);
			static void drawTexture(Texture &texture, glm::vec2 &pos);
			static void drawTexture(Texture &texture, glm::vec2 &pos, glm::vec2 &size, glm::vec4 &color);
			static void startBatch();
			static void reBatch();
			static void render();
			static void clear();
			static void clearColor(float r, float g, float b, float a);
			static void end();
		private:
			static Shader *shader;
			static Buffer *vbo;
			static Buffer *ibo;
			static VertexArray *vao;
			static unsigned int quadsCount;
			static Texture *textureSlots[10];
			static std::string textureName[10];
	};

}

#endif
