#pragma once
#include "../entities/Enemy.h"
#include <memory>
#include <vector>

class MovementSystem {
public:
  static void update(std::vector<std::unique_ptr<Enemy>> &enemies, float dt);
};