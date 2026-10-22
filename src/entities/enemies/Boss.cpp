#include "../../../include/entities/enemies/Boss.h"

Boss::Boss(std::vector<Vector2> *camino, float x, float y)
    : Enemy(500, 40.0f, 20, camino, x, y, LoadTexture("../assets/orc.png"), 100) {}

Boss::~Boss() {}