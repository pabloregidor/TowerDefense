#include "../../include/entities/Entity.h"

Vector2 Entity::calcularMovimiento(Vector2 posicion, Vector2 destino,
                                   float velocidad) {
  float delta = GetFrameTime();
  float paso = velocidad * delta;

  float distancia = Vector2Distance(destino, posicion);
  if (distancia <= paso) {
    return {destino.x, destino.y};
  } else {
    Vector2 direccion = Vector2Normalize(Vector2Subtract(destino, posicion));
    return {posicion.x + (direccion.x * paso),
            posicion.y + (direccion.y * paso)};
  }
}

void Entity::Dibujar() {
  int row = (int)(position.y / TILE_SIZE);
  float depthScale =
      1.0f - (row * INCLINED_DEPTH_SCALE_STEP);
  if (depthScale < INCLINED_DEPTH_SCALE_MIN) {
    depthScale = INCLINED_DEPTH_SCALE_MIN;
  }

  float screenX = position.x;
  float screenY = position.y * INCLINED_VERTICAL_SCALE;

  float width = (float)TILE_SIZE * depthScale;
  float height = width;
  if (renderable.texture.width > 0 && renderable.texture.height > 0) {
    height = width * ((float)renderable.texture.height /
                      (float)renderable.texture.width);
  }
  // Clamp del alto para evitar sprites desorbitados en pantalla
  float maxHeight = (float)TILE_SIZE * 3.0f;
  if (height > maxHeight) {
    float scale = maxHeight / height;
    height = maxHeight;
    width *= scale;
  }
  renderer->drawTexture(renderable.texture, screenX, screenY, width, height,
                        true);
}

Entity::~Entity() {}