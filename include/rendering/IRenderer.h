#pragma once
#include "../raylib.h"
#include <string>

class IRenderer {
public:
  virtual ~IRenderer() = default;
  virtual Texture2D loadTexture(const std::string &path) = 0;
  // Dibuja la textura con ancho/alto dados. Si anchorBottom es true, el
  // origen se sitúa en el centro inferior (base del sprite); si no, en el
  // centro.
  virtual void drawTexture(const Texture2D &texture, float x, float y,
                           float width, float height,
                           bool anchorBottom = true) = 0;
};