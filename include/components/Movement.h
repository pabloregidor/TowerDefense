#pragma once
#include "../raylib.h"
#include <vector>

struct Movement {
  float speed = 0.0f;
  std::vector<Vector2> *path = nullptr;
  int targetIndex = 0;
};