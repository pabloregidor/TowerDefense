#include "../Enemy.h"
#include <vector>

class Goblin : public Enemy {
public:
  Goblin(std::vector<Vector2> *camino, float x, float y, Texture2D textura, IRenderer &r);
  ~Goblin();
};
