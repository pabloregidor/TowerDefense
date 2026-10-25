#include "../../../include/entities/enemies/Goblin.h"

Goblin::Goblin(std::vector<Vector2> *camino, float x, float y,
               Texture2D textura, IRenderer &r)
    : Enemy(50, 120.0f, 3, camino, x, y, textura, 5, r) {}

Goblin::~Goblin() {};
