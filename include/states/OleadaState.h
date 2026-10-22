#pragma once
#include "IGameState.h"

// Oleada en curso: spawnea enemigos por temporizador hasta agotar la
// cuota y avanza el mundo (movimiento + combate).
class OleadaState : public IGameState {
public:
  void update(Game &game) override;
  void draw(Game &game) override;
  void handleInput(Game &game) override;

private:
  bool iniciado = false;
  float timerSpawn = 1.0f;
  int restantes = 0; // de la cuota non-boss de la formula
  int spawnados = 0; // enemigos ya spawneados en esta oleada
};
