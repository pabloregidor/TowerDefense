#pragma once
#include "../raylib.h"
#include <string>

class IRenderer {
public:
  virtual ~IRenderer() = default;
  virtual Texture2D loadTexture(const std::string &path) = 0;
  virtual void drawTexture(const Texture2D &texture, float x, float y,
                           float size) = 0;
};