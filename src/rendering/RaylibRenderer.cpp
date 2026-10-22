#include "../../include/rendering/RaylibRenderer.h"

Texture2D RaylibRenderer::loadTexture(const std::string &path) {
  return LoadTexture(path.c_str());
}

void RaylibRenderer::drawTexture(const Texture2D &texture, float x, float y,
                                 float size) {
  Rectangle fuente = {0.0f, 0.0f, (float)texture.width, (float)texture.height};
  Rectangle destino = {x, y, size, size};
  Vector2 origen = {size / 2.0f, size / 2.0f};
  DrawTexturePro(texture, fuente, destino, origen, 0.0f, WHITE);
}