#pragma once

class Game;

class IGameState {
public:
  virtual ~IGameState() = default;
  virtual void update(Game &game) = 0;
  virtual void draw(Game &game) = 0;
  virtual void handleInput(Game &game) = 0;
};