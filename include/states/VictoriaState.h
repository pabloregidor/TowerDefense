#pragma once
#include "IGameState.h"

// Victoria: oleada final del nivel 3 completada; muestra puntuacion.
class VictoriaState : public IGameState {
public:
  void update(Game &game) override;
  void draw(Game &game) override;
  void handleInput(Game &game) override;
};
