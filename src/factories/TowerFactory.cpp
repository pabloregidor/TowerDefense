#include "../../include/factories/TowerFactory.h"
#include "../../include/entities/towers/TorreMago.h"
#include "../../include/entities/towers/TorreLancero.h"

TowerFactory::TowerFactory(IRenderer &r, EventBus &b) : renderer(r), bus(b) {
  (void)renderer;
  (void)bus;
}

std::unique_ptr<Tower> TowerFactory::createMago(float x, float y) {
  return std::make_unique<TorreMago>(x, y, renderer, bus);
}

std::unique_ptr<Tower> TowerFactory::createLancero(float x, float y) {
  return std::make_unique<TorreLancero>(x, y, renderer, bus);
}