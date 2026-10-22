#pragma once
#include "../rendering/IRenderer.h"
#include "../events/EventBus.h"
#include "../entities/Tower.h"
#include <memory>

class TowerFactory {
  IRenderer &renderer;
  EventBus &bus;

public:
  TowerFactory(IRenderer &r, EventBus &b);
  std::unique_ptr<Tower> createArcher(float x, float y);
  std::unique_ptr<Tower> createCanon(float x, float y);
};