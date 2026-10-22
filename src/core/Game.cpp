#include "../../include/core/Game.h"
#include <cstdio>
#include <memory>

Game::Game()
    : renderer(), eventBus(), enemyFactory(renderer, eventBus),
      towerFactory(renderer, eventBus), projectileFactory(renderer, eventBus),
      currentState(std::make_unique<PreparacionState>()), mapa(), jugador() {}

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

Game::~Game() {}