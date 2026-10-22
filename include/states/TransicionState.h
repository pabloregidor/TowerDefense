#pragma once
#include "IGameState.h"

// Transicion de nivel: aplica el reset (oro, torres, mapa) una vez y
// pasa a PreparacionState. Solo se ejecuta sin enemigos vivos.
class TransicionState : public IGameState {
public:
  void update(Game &game) override;
  void draw(Game &game) override;
  void handleInput(Game &game) override;

private:
  bool aplicada = false;
};
