#include "../../../include/entities/towers/TorreMago.h"

TorreMago::TorreMago(float x, float y, IRenderer &r, EventBus &bus)
    : Tower(x, y, LoadTexture("../assets/archerTower.png"), 10, 3, 50, 15, r,
            bus) {}

TorreMago::~TorreMago() {}
