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
}void RenderSystem::drawHUD(Game &game) {
  const PlayerStats &p = game.getJugador();
  char buf[128];

  snprintf(buf, sizeof(buf), "Nivel %d  Oleada %d", p.nivel, p.oleada);
  DrawText(buf, 10, 10, 20, BLACK);

  snprintf(buf, sizeof(buf), "Vida: %d   Oro: %d   Puntos: %d", p.vida,
           p.oro, p.points);
  DrawText(buf, 10, 35, 20, BLACK);

  const char *tipo = (game.getTipoSeleccionado() == 2) ? "Canon" : "Archer";
  snprintf(buf, sizeof(buf), "Torre seleccionada: %s (coste %d)", tipo,
           game.costeSeleccionado());
  DrawText(buf, 10, 60, 20, BLACK);
}
