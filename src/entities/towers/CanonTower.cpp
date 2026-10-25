#include "../../../include/entities/towers/CanonTower.h"

TipoTorre CanonTower::getTipoTorre() { return TORRE_LANCERO; }

CanonTower::CanonTower(float x, float y, IRenderer &r, EventBus &bus)
    : Tower(x, y, LoadTexture("../assets/canonTower.png"), 25, 6, 70, 10, r,
            bus) {};

CanonTower::~CanonTower() {}
