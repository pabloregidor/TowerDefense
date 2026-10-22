#pragma once
#include "IRenderer.h"

class RaylibRenderer : public IRenderer {
public:
  Texture2D loadTexture(const std::string &path) override;
  void drawTexture(const Texture2D &texture, float x, float y, float size) override;
};