#include "../../../include/entities/enemies/Boss.h"

Boss::Boss(std::vector<Vector2> *camino, float x, float y, Texture2D textura,
           IRenderer &r)
    : Enemy(500, 40.0f, 20, camino, x, y, textura, 100, r) {}

Boss::~Boss() {}
