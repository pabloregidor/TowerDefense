#pragma once
#include "IGameState.h"

// Estado entre oleadas: spawning en pausa; la siguiente oleada
// arranca solo con input del jugador (Enter/Espacio).
class PreparacionState : public IGameState {
public:
  void update(Game &game) override;
  void draw(Game &game) override;
  void handleInput(Game &game) override;
};
