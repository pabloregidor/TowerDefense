#pragma once
#include "IRenderer.h"
#include <map>

class RaylibRenderer : public IRenderer {
public:
  Texture2D loadTexture(const std::string &path) override;
  void drawTexture(const Texture2D &texture, float x, float y, float width,
                   float height, bool anchorBottom = true) override;

private:
  std::map<std::string, Texture2D> cache;
  void loadTextureFallback(const std::string &path, Texture2D &out);
};