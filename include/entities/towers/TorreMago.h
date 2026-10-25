#include "../Tower.h"

class TorreMago : public Tower {
public:
  TorreMago(float x, float y, Texture2D textura, IRenderer &r, EventBus &bus);
  ~TorreMago();
};
