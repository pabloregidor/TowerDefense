#pragma once
#include "IGameState.h"

// Derrota: vida <= 0; parada de spawning y muestra puntuacion.
class DerrotaState : public IGameState {
public:
  void update(Game &game) override;
  void draw(Game &game) override;
  void handleInput(Game &game) override;
};
