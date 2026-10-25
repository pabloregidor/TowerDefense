#include "../Tower.h"

class ArcherTower : public Tower {
public:
  ArcherTower(float x, float y, IRenderer &r, EventBus &bus);
  ~ArcherTower();
};
