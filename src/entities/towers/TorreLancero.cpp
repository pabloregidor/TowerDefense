#include "../../../include/entities/towers/TorreLancero.h"

TipoTorre TorreLancero::getTipoTorre() { return TORRE_LANCERO; }

TorreLancero::TorreLancero(float x, float y, Texture2D textura, IRenderer &r,
                           EventBus &bus)
    : Tower(x, y, textura, 25, 6, 70, 10, r, bus) {}

TorreLancero::~TorreLancero() {}
