#include "../../../include/entities/enemies/Goblin.h"

Goblin::Goblin(std::vector<Vector2> *camino, float x, float y)
    : Enemy(50, 120.0f, 3, camino, x, y, LoadTexture("../assets/goblin.png"), 5) {}

Goblin::~Goblin() {};
