#include "../../include/rendering/RaylibRenderer.h"

Texture2D RaylibRenderer::loadTexture(const std::string &path) {
  return LoadTexture(path.c_str());
}

void RaylibRenderer::drawTexture(const Texture2D &texture, float x, float y,
                                 float width, float height, bool anchorBottom) {
  if (texture.id == 0) {
    // Fallback: placeholder visible si falta la textura
    DrawRectangle((int)(x - width / 2.0f),
                  (int)(y - (anchorBottom ? height : height / 2.0f)),
                  (int)width, (int)height, MAGENTA);
    return;
  }
  Rectangle fuente = {0.0f, 0.0f, (float)texture.width, (float)texture.height};
  Rectangle destino = {x, y, width, height};
  Vector2 origen = anchorBottom ? Vector2{width / 2.0f, height}
                                : Vector2{width / 2.0f, height / 2.0f};
  DrawTexturePro(texture, fuente, destino, origen, 0.0f, WHITE);
}