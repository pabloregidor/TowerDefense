#pragma once
#include "Enemy.h"
#include "Entity.h"

class Projectile : public Entity {
protected:
  int danio;
  bool activo;
  float velocidad;
  Enemy *objetivo;

public:
  Projectile(float x, float y, Texture2D textura, float velocidad,
             Enemy *objetivo, IRenderer &r);
  virtual bool Actualizar();
  virtual bool EstaActivo() { return activo; };
  virtual ~Projectile();
};
