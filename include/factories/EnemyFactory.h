#pragma once
#include "../rendering/IRenderer.h"
#include "../events/EventBus.h"
#include "../entities/Enemy.h"
#include <memory>
#include <vector>

class EnemyFactory {
  IRenderer &renderer;
  EventBus &bus;

public:
  EnemyFactory(IRenderer &r, EventBus &b);
  std::unique_ptr<Enemy> createGoblin(std::vector<Vector2> *camino, float x,
                                      float y);
  std::unique_ptr<Enemy> createOrc(std::vector<Vector2> *camino, float x,
                                   float y);
  std::unique_ptr<Enemy> createBoss(std::vector<Vector2> *camino, float x,
                                    float y);
};