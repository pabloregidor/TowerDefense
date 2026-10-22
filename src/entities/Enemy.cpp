#include "../../include/entities/Enemy.h"
#include <vector>

Enemy::Enemy(int hp, float velocidad, int danio, std::vector<Vector2> *camino,
             float x, float y, Texture2D textura, int oro)
    : Entity(x, y, textura) {
  this->hp = hp;
  this->velocidad = velocidad;
  this->camino = camino;
  this->casillaDestino = 0;
  this->vivo = true;
  this->golpear = false;
  this->danio = danio;
  this->oro = oro;
}

void Enemy::recibirDanio(int danioRecibido) {
  this->hp -= danioRecibido;

  if (this->hp <= 0) {
    morir();
  }
}

void Enemy::caminar() {
  if (casillaDestino >= camino->size()) {
    golpear = true;
    morir();
    return;
  }

  Vector2 destino = camino->at(casillaDestino);

  Vector2 nuevaPosicion =
      calcularMovimiento({position.x, position.y}, destino, velocidad);

  position.x = nuevaPosicion.x;
  position.y = nuevaPosicion.y;

  if (position.x == destino.x && position.y == destino.y)
    casillaDestino++;
}

void Enemy::morir() { this->vivo = false; }

Enemy::~Enemy() {}
