#include "../../include/factories/ProjectileFactory.h"
#include "../../include/core/Oleadas.h"

ProjectileFactory::ProjectileFactory(IRenderer &r, EventBus &b)
    : renderer(r), bus(b) {
  (void)renderer;
  (void)bus;
}

std::unique_ptr<Projectile> ProjectileFactory::createProjectile(
    float x, float y, float velocidad, Enemy *objetivo, int danio,
    int tipoTorre) {
  const std::string &nombre =
      (tipoTorre == TORRE_LANCERO) ? PROJECTILE_LANCERO_ASSET
                                   : PROJECTILE_MAGO_ASSET;
  return std::make_unique<Projectile>(
      x, y, renderer.loadTexture(assetPath(nombre)), velocidad, objetivo,
      danio, renderer);
}