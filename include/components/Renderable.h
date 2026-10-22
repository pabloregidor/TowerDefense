#pragma once
#include "../raylib.h"

struct Renderable {
  Texture2D texture{};
  float width = 40.0f;
  float height = 40.0f;
};