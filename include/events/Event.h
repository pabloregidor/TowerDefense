#pragma once
#include "../raylib.h"

struct Event {
  virtual ~Event() = default;
};

struct EnemyDiedEvent : Event {
  int gold = 0;
  Vector2 position{};
};

struct EnemyReachedEndEvent : Event {
  int damage = 0;
};

struct WaveCompletedEvent : Event {
  int level = 0;
  int wave = 0;
  bool perfect = false;
};

class Enemy; // Reenviar para targetEnemy (no incluir Enemy.h aquí)

struct TowerShootEvent : Event {
  Vector2 position{};
  Enemy *targetEnemy = nullptr;
  float speed = 0.0f;
  int danio = 0;
  int tipoTorre = 0; // TipoTorre
};