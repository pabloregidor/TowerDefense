#include "../../include/entities/Tower.h"

Tower::Tower(float x, float y, Texture2D textura, int danio, int cd, int coste,
             int rango)
    : Entity(x, y, textura) {
  this->danio = danio;
  this->cd = cd;
  this->coste = coste;
  this->rango = rango;
};

void Tower::atacar(const std::vector<std::unique_ptr<Enemy>> &objetivo) {}

int Tower::vender() { return this->coste * 0.65; }

Tower::~Tower() {}
