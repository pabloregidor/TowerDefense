#pragma once
#include "../raylib.h"
#include "../core/Oleadas.h"
#include "../events/EventBus.h"
#include "Enemy.h"
#include "Entity.h"
#include <memory>
#include <vector>

class Tower : public Entity {
protected:
  int danio, cd, coste, rango;
  int cdRestante;
  EventBus &bus;

public:
  Tower(float x, float y, Texture2D textura, int danio, int cd, int coste,
        int rango, IRenderer &r, EventBus &bus);

  virtual TipoTorre getTipoTorre() { return TORRE_MAGO; }

  virtual void atacar(const std::vector<std::unique_ptr<Enemy>> &objetivo);
  virtual int vender();
  int getCoste() const { return coste; }
  virtual ~Tower();
};
