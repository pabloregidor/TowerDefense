#include "../../include/systems/RenderSystem.h"

void RenderSystem::draw(Game &game) {
  game.getMapa().Draw();

  for (auto &e : game.getEnemigos()) {
    e->Dibujar();
  }

  for (auto &t : game.getTorres()) {
    t->Dibujar();
  }

  for (auto &p : game.getProyectiles()) {
    p->Dibujar();
  }
}
