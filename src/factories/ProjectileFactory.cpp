#include "../../include/factories/ProjectileFactory.h"

ProjectileFactory::ProjectileFactory(IRenderer &r, EventBus &b)
    : renderer(r), bus(b) {
  (void)renderer;
  (void)bus;
}

std::unique_ptr<Projectile> ProjectileFactory::createProjectile(float x, float y,
                                                               float velocidad,
                                                               Enemy *objetivo) {
  return std::make_unique<Projectile>(
      x, y, renderer.loadTexture("../assets/goblin.png"), velocidad, objetivo,
      renderer);
}