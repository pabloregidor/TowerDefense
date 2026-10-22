#include "../../../include/entities/towers/CanonTower.h"

CanonTower::CanonTower(float x, float y, IRenderer &r)
    : Tower(x, y, LoadTexture("../assets/canonTower.png"), 25, 6, 70, 10, r) {};

CanonTower::~CanonTower() {}
