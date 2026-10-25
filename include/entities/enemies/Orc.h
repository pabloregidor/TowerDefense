#include "../Enemy.h"

class Orc : public Enemy {
public:
  Orc(std::vector<Vector2> *camino, float x, float y, Texture2D textura, IRenderer &r);
  ~Orc();
};
