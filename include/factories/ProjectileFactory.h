#pragma once
#include "../rendering/IRenderer.h"
#include "../events/EventBus.h"
#include "../entities/Projectile.h"
#include <memory>

class ProjectileFactory {
  IRenderer &renderer;
  EventBus &bus;

public:
  ProjectileFactory(IRenderer &r, EventBus &b);
  std::unique_ptr<Projectile> createProjectile(float x, float y, float velocidad,
                                              Enemy *objetivo);
};