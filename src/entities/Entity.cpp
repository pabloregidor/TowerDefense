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
  renderer->drawTexture(renderable.texture, position.x, position.y,
                        (float)TILE_SIZE);
}

Entity::~Entity() {}
