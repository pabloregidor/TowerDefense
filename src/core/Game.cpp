#include "../../include/core/Game.h"
#include <cstdio>
#include <memory>

Game::Game()
    : renderer(), eventBus(), enemyFactory(renderer, eventBus),
      towerFactory(renderer, eventBus), projectileFactory(renderer, eventBus),
      currentState(std::make_unique<PreparacionState>()), mapa(), jugador() {
  // Cualquier enemigo que llegue al final marca la oleada como no perfecta
  eventBus.subscribe<EnemyReachedEndEvent>(
      [this](const EnemyReachedEndEvent &e) {
        (void)e;
        danioEnOleada = true;
      });

  // Disparo de torre: la torre solo publica el intento, la creación del
  // proyectil se centraliza aquí via ProjectileFactory.
  eventBus.subscribe<TowerShootEvent>(
      [this](const TowerShootEvent &e) {
        if (e.targetEnemy != nullptr && e.targetEnemy->estaVivo()) {
          auto proyectil = projectileFactory.createProjectile(
              e.position.x, e.position.y, e.speed, e.targetEnemy, e.danio);
          if (proyectil != nullptr) {
            proyectiles.push_back(std::move(proyectil));
          }
        }
      });
}

void Game::Actualizar() {
  if (currentState != nullptr) {
    currentState->update(*this);
  }
};

void Game::Draw() {
  if (currentState != nullptr) {
    currentState->draw(*this);
  }
}

void Game::GestionarInput() {
  if (currentState != nullptr) {
    currentState->handleInput(*this);
  }
}

void Game::SpawnEnemy(TipoEnemigo tipo) {
  Vector2 salida = mapa.GetCaminoPtr()->at(0);
  std::unique_ptr<Enemy> nuevoEnemigo = nullptr;

  switch (tipo) {
  case GOBLIN:
    nuevoEnemigo = enemyFactory.createGoblin(mapa.GetCaminoPtr(), salida.x, salida.y);
    break;
  case ORC:
    nuevoEnemigo = enemyFactory.createOrc(mapa.GetCaminoPtr(), salida.x, salida.y);
    break;
  case BOSS:
    nuevoEnemigo = enemyFactory.createBoss(mapa.GetCaminoPtr(), salida.x, salida.y);
    break;
  }

  if (nuevoEnemigo != nullptr) {
    enemigos.push_back(std::move(nuevoEnemigo));
  }
}

void Game::CambiarMapa(int nivel) {
  if (!enemigos.empty()) {
    printf("No se puede cambiar de mapa con enemigos vivos.\n");
    return;
  }
  mapa = Map(nivel);
}

void Game::CambiarEstado(std::unique_ptr<IGameState> nuevo) {
  if (nuevo != nullptr) {
    currentState = std::move(nuevo);
  }
}

void Game::ConstruirTorre(int col, int fil) {
  if (mapa.GetTipoCasilla(col, fil) != 0) {
    printf("No se puede construir en el camino.\n");
    return;
  }
  for (auto &t : torres) {
    if ((int)(t->getX() / TILE_SIZE) == col &&
        (int)(t->getY() / TILE_SIZE) == fil) {
      printf("¡Ya hay una torre ahí!\n");
      return;
    }
  }
  int coste = costeSeleccionado();
  if (jugador.oro < coste) {
    printf("Oro insuficiente para construir (necesitas %d).\n", coste);
    return;
  }
  float cx = (float)col * TILE_SIZE + TILE_SIZE / 2.0f;
  float cy = (float)fil * TILE_SIZE + TILE_SIZE / 2.0f;
  std::unique_ptr<Tower> nueva = nullptr;
  if (tipoSeleccionado == 2) {
    nueva = towerFactory.createCanon(cx, cy);
  } else {
    nueva = towerFactory.createArcher(cx, cy);
  }
  if (nueva != nullptr) {
    torres.push_back(std::move(nueva));
    jugador.oro -= coste; // descontar solo tras el push real
  }
}

Game::~Game() {}