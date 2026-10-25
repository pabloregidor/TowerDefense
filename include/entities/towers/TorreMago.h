#include "../Tower.h"

class TorreMago : public Tower {
public:
  TorreMago(float x, float y, IRenderer &r, EventBus &bus);
  ~TorreMago();
};
