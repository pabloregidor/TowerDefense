#include "../../include/entities/Tower.h"
#include "../../include/events/Event.h"

Tower::Tower(float x, float y, Texture2D textura, int danio, int cd, int coste,
             int rango, IRenderer &r, EventBus &bus)
    : Entity(x, y, textura, r), bus(bus) {
  this->danio = danio;
  this->cd = cd;
  this->cdRestante = (float)cd; // segundos
  this->coste = coste;
  this->rango = rango;
}

void Tower::atacar(const std::vector<std::unique_ptr<Enemy>> &objetivo) {
  // Cooldown: se descuenta un frame por llamada y solo se dispara al llegar
  // a 0 (Archer 3, Canon 6 frames, valor vigente).
  if (cdRestante > 0.0f) {
    cdRestante -= GetFrameTime(); // por frame en segundos
    return;
  }

  // Selección de objetivo: enemigo vivo más cercano dentro de rango
  // (en tiles: rango * TILE_SIZE píxeles).
  Enemy *masCercano = nullptr;
  float distancia = 0.0f;
  float rangoPx = (float)this->rango * TILE_SIZE;
  for (auto &e : objetivo) {
    if (!e->estaVivo()) {
      continue;
    }
    float d = Vector2Distance({position.x, position.y},
                              {e->getX(), e->getY()});
    if (d <= rangoPx && (masCercano == nullptr || d < distancia)) {
      masCercano = e.get();
      distancia = d;
    }
  }
  if (masCercano == nullptr) {
    return;
  }

  TowerShootEvent ev;
  ev.position = {position.x, position.y};
  ev.targetEnemy = masCercano;
  ev.speed = 180.0f; // velocidad del proyectil (px/s)
  ev.danio = this->danio;
  ev.tipoTorre = getTipoTorre();
  bus.publish(ev);

  cdRestante = (float)this->cd; // 3 s (mago) / 6 s (lanzero)
}

int Tower::vender() { return this->coste * 0.65; }

Tower::~Tower() {}
