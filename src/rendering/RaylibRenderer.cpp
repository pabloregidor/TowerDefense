#include "../../include/rendering/RaylibRenderer.h"
#include <unordered_map>

void RaylibRenderer::loadTextureFallback(const std::string &path,
                                        Texture2D &out) {
  out = LoadTexture(path.c_str());
  if (out.width <= 0) {
    // Ejecutar desde build/ -> probar la ruta relativa al proyecto
    out = LoadTexture(("../" + path).c_str());
  }
}

Texture2D RaylibRenderer::loadTexture(const std::string &path) {
  auto it = cache.find(path);
  if (it != cache.end())
    return it->second; // ya cargada: reuso

  Texture2D texture{};
  loadTextureFallback(path, texture);
  if (texture.id != 0) {
    SetTextureFilter(texture, TEXTURE_FILTER_POINT);
    cache[path] = texture; // primera carga: cache
  }
  return texture;
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