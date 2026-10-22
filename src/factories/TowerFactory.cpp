#include "../../include/factories/TowerFactory.h"
#include "../../include/entities/towers/ArcherTower.h"
#include "../../include/entities/towers/CanonTower.h"

TowerFactory::TowerFactory(IRenderer &r, EventBus &b) : renderer(r), bus(b) {
  (void)renderer;
  (void)bus;
}

std::unique_ptr<Tower> TowerFactory::createArcher(float x, float y) {
  return std::make_unique<ArcherTower>(x, y);
}

std::unique_ptr<Tower> TowerFactory::createCanon(float x, float y) {
  return std::make_unique<CanonTower>(x, y);
}