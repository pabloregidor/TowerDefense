#include "../../../include/entities/enemies/Orc.h"

Orc::Orc(std::vector<Vector2> *camino, float x, float y, Texture2D textura,
         IRenderer &r)
    : Enemy(100, 60.0f, 10, camino, x, y, textura, 10, r) {}
Orc::~Orc() {};
