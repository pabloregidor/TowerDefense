#include "../../include/states/TransicionState.h"
#include "../../include/core/Game.h"
#include "../../include/states/PreparacionState.h"
#include <memory>

void TransicionState::update(Game &game) {
  if (aplicada)
    return;

  // Reset de nivel: vida se conserva; oro a 100, torres fuera
  // (sin reembolso), oleada a 0, mapa nuevo. Solo llega aqui sin
  // enemigos vivos, de modo que el rebuild no deja punteros colgantes
  // al camino del mapa anterior.
  PlayerStats &p = game.getJugador();
  p.oro = 100;
  p.oleada = 0;
  p.nivel++;

  game.getTorres().clear();
  game.CambiarMapa(p.nivel);

  aplicada = true;
  game.CambiarEstado(std::make_unique<PreparacionState>());
}

void TransicionState::draw(Game &game) {
  char buf[64];
  snprintf(buf, sizeof(buf), "Nivel %d completado", game.getJugador().nivel);
  DrawText(buf, SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2, 20, BLACK);
}

void TransicionState::handleInput(Game &game) { (void)game; }
