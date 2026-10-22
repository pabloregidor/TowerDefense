#include "../../../include/entities/towers/ArcherTower.h"

ArcherTower::ArcherTower(float x, float y, IRenderer &r)
    : Tower(x, y, LoadTexture("../assets/archerTower.png"), 10, 3, 50, 15, r) {}

ArcherTower::~ArcherTower() {}
