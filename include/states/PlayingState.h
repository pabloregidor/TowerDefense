#pragma once
#include "IGameState.h"

class PlayingState : public IGameState {
public:
  void update(Game &game) override;
  void draw(Game &game) override;
  void handleInput(Game &game) override;
};