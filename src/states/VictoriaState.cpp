#include "../../include/states/VictoriaState.h"
#include "../../include/core/Game.h"
#include <cstdio>

void VictoriaState::update(Game &game) {
  // Fin de partida: no hay mas spawning ni logica
  (void)game;
}

void VictoriaState::draw(Game &game) {
  char buf[64];

  DrawText("VICTORIA", SCREEN_WIDTH / 2 - 90, SCREEN_HEIGHT / 2 - 80, 40,
           VIOLET);

  snprintf(buf, sizeof(buf), "Puntuacion final: %d",
           game.getJugador().points);
  DrawText(buf, SCREEN_WIDTH / 2 - 110, SCREEN_HEIGHT / 2, 20, BLACK);
}

void VictoriaState::handleInput(Game &game) { (void)game; }
