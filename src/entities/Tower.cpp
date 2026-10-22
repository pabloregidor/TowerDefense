#include "../../include/entities/Tower.h"

Tower::Tower(float x, float y, Texture2D textura, int danio, int cd, int coste,
             int rango, IRenderer &r)
    : Entity(x, y, textura, r) {
  this->danio = danio;
  this->cd = cd;
  this->coste = coste;
  this->rango = rango;
};

void Tower::atacar(const std::vector<std::unique_ptr<Enemy>> &objetivo) {}

int Tower::vender() { return this->coste * 0.65; }

Tower::~Tower() {}
