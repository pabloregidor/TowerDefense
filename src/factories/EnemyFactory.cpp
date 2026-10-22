#include "../../include/factories/EnemyFactory.h"
#include "../../include/entities/enemies/Goblin.h"
#include "../../include/entities/enemies/Orc.h"
#include "../../include/entities/enemies/Boss.h"

EnemyFactory::EnemyFactory(IRenderer &r, EventBus &b) : renderer(r), bus(b) {
  (void)renderer;
  (void)bus;
}

std::unique_ptr<Enemy> EnemyFactory::createGoblin(std::vector<Vector2> *camino,
                                                  float x, float y) {
  return std::make_unique<Goblin>(camino, x, y);
}

std::unique_ptr<Enemy> EnemyFactory::createOrc(std::vector<Vector2> *camino,
                                              float x, float y) {
  return std::make_unique<Orc>(camino, x, y);
}

std::unique_ptr<Enemy> EnemyFactory::createBoss(std::vector<Vector2> *camino,
                                               float x, float y) {
  return std::make_unique<Boss>(camino, x, y);
}