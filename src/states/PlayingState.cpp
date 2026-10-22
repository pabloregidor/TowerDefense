#include "../../include/states/PlayingState.h"
#include "../../include/core/Game.h"
#include "../../include/systems/MovementSystem.h"
#include <cstdio>

void PlayingState::update(Game &game) {
  MovementSystem::update(game.getEnemigos(), GetFrameTime());
  game.ActualizarEnemigos();
  game.ActualizarTorres();
  game.ActualizarProyectiles();
}

void PlayingState::draw(Game &game) {
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

void PlayingState::handleInput(Game &game) {
  if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
    Vector2 raton = GetMousePosition();

    int col = (int)(raton.x / TILE_SIZE);
    int fil = (int)(raton.y / TILE_SIZE);

    if (game.getMapa().GetTipoCasilla(col, fil) == 0) {
      bool ocupado = false;
      for (auto &t : game.getTorres()) {
        int tCol = (int)(t->getX() / TILE_SIZE);
        int tFil = (int)(t->getY() / TILE_SIZE);
        if (tCol == col && tFil == fil) {
          ocupado = true;
          break;
        }
      }

      if (!ocupado) {
        // Construcción deshabilitada hasta change de combate/economía
      } else {
        printf("¡Ya hay una torre ahí!\n");
      }
    } else {
      printf("No se puede construir en el camino.\n");
    }
  }
}
