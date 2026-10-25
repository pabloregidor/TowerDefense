#include "../Tower.h"

class TorreLancero : public Tower {
public:
  TorreLancero(float x, float y, IRenderer &r, EventBus &bus);
  ~TorreLancero();
  virtual TipoTorre getTipoTorre() override;
};
