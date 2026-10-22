#include "../../include/states/DerrotaState.h"
#include "../../include/core/Game.h"
#include <cstdio>

void DerrotaState::update(Game &game) {
  // Fin de partida: no hay mas spawning ni logica
  (void)game;
}

void DerrotaState::draw(Game &game) {
  char buf[64];

  DrawText("GAME OVER", SCREEN_WIDTH / 2 - 90, SCREEN_HEIGHT / 2 - 80, 40, RED);

  snprintf(buf, sizeof(buf), "Puntuacion final: %d",
           game.getJugador().points);
  DrawText(buf, SCREEN_WIDTH / 2 - 110, SCREEN_HEIGHT / 2, 20, BLACK);
}

void DerrotaState::handleInput(Game &game) { (void)game; }
