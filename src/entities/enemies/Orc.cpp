#include "../../../include/entities/enemies/Orc.h"

Orc::Orc(std::vector<Vector2> *camino, float x, float y, IRenderer &r)
    : Enemy(100, 60.0f, 10, camino, x, y, LoadTexture("../assets/orc.png"), 10, r) {}
Orc::~Orc() {};
