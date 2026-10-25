#include "../Tower.h"

class CanonTower : public Tower {
public:
  CanonTower(float x, float y, IRenderer &r, EventBus &bus);
  ~CanonTower();
  virtual TipoTorre getTipoTorre() override;
};
