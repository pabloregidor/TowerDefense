#pragma once
#include "../core/Game.h"

class RenderSystem {
public:
  static void draw(Game &game);
  // HUD: nivel, oleada, vida, oro y puntos
  static void drawHUD(Game &game);
};
