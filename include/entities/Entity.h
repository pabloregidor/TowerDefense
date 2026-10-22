#pragma once
#include "../Constants.h"
#include "../raylib.h"
#include "../raymath.h"
#include "../components/Position.h"
#include "../rendering/IRenderer.h"
#include "../components/Renderable.h"
#include "../components/Health.h"
#include "../components/Movement.h"
#include "../components/Combat.h"
#include "../components/Reward.h"

class Entity {
protected:
  Position position;
  Renderable renderable;
  Health health;
  Movement movement;
  Combat combat;
  Reward reward;

  IRenderer *renderer;

  Entity(float x, float y, Texture2D textura, IRenderer &r)
      : renderer(&r) {
    position.x = x;
    position.y = y;
    renderable.texture = textura;
  }

public:
  virtual void Dibujar();
  virtual Vector2 calcularMovimiento(Vector2 posicion, Vector2 destino,
                                     float velocidad);
  float getX() { return position.x; }
  float getY() { return position.y; }
  Position &getPosition() { return position; }
  Renderable &getRenderable() { return renderable; }
  Health &getHealth() { return health; }
  Movement &getMovement() { return movement; }
  Combat &getCombat() { return combat; }
  Reward &getReward() { return reward; }
  virtual ~Entity();
};
