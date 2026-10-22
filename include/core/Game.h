#pragma once
#include "../../include/core/Oleadas.h"
#include "../../include/core/PlayerStats.h"
#include "../entities/Enemy.h"
#include "../entities/Projectile.h"
#include "../entities/Tower.h"
#include "../entities/enemies/Goblin.h"
#include "../entities/enemies/Orc.h"
#include "../entities/enemies/Boss.h"
#include "../entities/towers/ArcherTower.h"
#include "../entities/towers/CanonTower.h"
#include "Map.h"
#include "../rendering/IRenderer.h"
#include "../rendering/RaylibRenderer.h"
#include "../events/EventBus.h"
#include "../factories/EnemyFactory.h"
#include "../factories/TowerFactory.h"
#include "../factories/ProjectileFactory.h"
#include "../states/IGameState.h"
#include "../states/PlayingState.h"
#include "../systems/MovementSystem.h"
#include <memory>
#include <vector>

class Game {
private:
  RaylibRenderer renderer;
  EventBus eventBus;
  EnemyFactory enemyFactory;
  TowerFactory towerFactory;
  ProjectileFactory projectileFactory;

  std::unique_ptr<IGameState> currentState;

  Map mapa;
  PlayerStats jugador;

  std::vector<std::unique_ptr<Enemy>> enemigos;
  std::vector<std::unique_ptr<Tower>> torres;
  std::vector<std::unique_ptr<Projectile>> proyectiles;

public:
  Game();
  ~Game();

  void Actualizar();
  void Draw();
  void GestionarInput();
  void SpawnEnemy(TipoEnemigo tipo);

  // Accessors for states/systems
  IGameState *getCurrentState() { return currentState.get(); }
  Map &getMapa() { return mapa; }
  PlayerStats &getJugador() { return jugador; }
  std::vector<std::unique_ptr<Enemy>> &getEnemigos() { return enemigos; }
  std::vector<std::unique_ptr<Tower>> &getTorres() { return torres; }
  std::vector<std::unique_ptr<Projectile>> &getProyectiles() { return proyectiles; }
  EventBus &getEventBus() { return eventBus; }
  IRenderer &getRenderer() { return renderer; }
};