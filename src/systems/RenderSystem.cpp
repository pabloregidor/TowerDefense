#include "../../include/systems/RenderSystem.h"
#include "../../include/entities/Entity.h"
#include <algorithm>
#include <vector>

void RenderSystem::draw(Game &game) {
  game.getMapa().Draw();

  struct Drawable {
    int row;
    Entity *entity;
  };
  std::vector<Drawable> drawables;
  for (auto &e : game.getEnemigos()) {
    drawables.push_back({(int)(e->getY() / TILE_SIZE), e.get()});
  }
  for (auto &t : game.getTorres()) {
    drawables.push_back({(int)(t->getY() / TILE_SIZE), t.get()});
  }
  for (auto &p : game.getProyectiles()) {
    drawables.push_back({(int)(p->getY() / TILE_SIZE), p.get()});
  }

  std::stable_sort(drawables.begin(), drawables.end(),
                   [](const Drawable &a, const Drawable &b) {
                     return a.row < b.row;
                   });

  for (auto &d : drawables) {
    if (d.entity) {
      d.entity->Dibujar();
    }
  }
}