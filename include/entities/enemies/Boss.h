#pragma once
#include "../Enemy.h"

class Boss : public Enemy {
public:
  Boss(std::vector<Vector2> *camino, float x, float y, Texture2D textura, IRenderer &r);
  ~Boss();
};