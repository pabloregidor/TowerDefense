#include "../../../include/entities/towers/TorreMago.h"

TorreMago::TorreMago(float x, float y, Texture2D textura, IRenderer &r,
                     EventBus &bus)
    : Tower(x, y, textura, 10, 3, 50, 15, r, bus) {}

TorreMago::~TorreMago() {}
