#include "../../include/entities/Projectile.h"

Projectile::Projectile(float x, float y, Texture2D textura, float velocidad,
                       Enemy *objetivo, int danio, IRenderer &r)
    : Entity(x, y, textura, r) {
  this->velocidad = velocidad;
  this->objetivo = objetivo;
  this->danio = danio;
  this->activo = true;
}

bool Projectile::Actualizar() {
  if (!activo)
    return false;

  if (objetivo == nullptr || !objetivo->estaVivo()) {
    activo = false;
    return false;
  }

  Vector2 posicionObjetivo = {objetivo->getX(), objetivo->getY()};
  float paso = velocidad * GetFrameTime(); // px este frame

  if (Vector2Distance({position.x, position.y}, posicionObjetivo) <= paso) {
    objetivo->recibirDanio(this->danio);
    activo = false;
    return true;
  }

  Vector2 nuevaPosicion = Entity::calcularMovimiento(
      {position.x, position.y}, posicionObjetivo, velocidad);

  position.x = nuevaPosicion.x;
  position.y = nuevaPosicion.y;

  return false;
}

void Projectile::Dibujar() {
  renderer->drawTexture(renderable.texture, position.x, position.y, 16.0f,
                        16.0f, false);
}

Projectile::~Projectile() {}
