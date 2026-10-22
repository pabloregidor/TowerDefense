#pragma once
#include "../raylib.h"
#include "../raymath.h"
#include "Entity.h"
#include <vector>

class Enemy : public Entity {
protected:
  int hp, casillaDestino, danio, oro;
  float velocidad;
  std::vector<Vector2> *camino; // OBTENER EL CAMINO ASI ES MAS RAPIDO Y COMODO
  bool golpear, vivo;

  Enemy(int hp, float velocidad, int danio, std::vector<Vector2> *camino,
        float x, float y, Texture2D textura, int oro, IRenderer &r);

public:
  virtual bool estaVivo() { return vivo; };
  virtual int getDanio() { return danio; };
  virtual int getOro() { return oro; };
  virtual bool hacerDanio() { return golpear; };
  virtual void recibirDanio(int danioRecibido);
  virtual void caminar();
  virtual void morir();
  virtual ~Enemy();
};
