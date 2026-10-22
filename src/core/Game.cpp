#include "../../include/core/Game.h"
#include <cstdio>
#include <memory>

Game::Game()
    : renderer(), eventBus(), enemyFactory(renderer, eventBus),
      towerFactory(renderer, eventBus), projectileFactory(renderer, eventBus),
      currentState(std::make_unique<PlayingState>()), mapa(), jugador() {}

void Game::Actualizar() {
  MovementSystem::update(enemigos, GetFrameTime());
  ActualizarEnemigos();
  ActualizarTorres();
  ActualizarProyectiles();
};

void Game::Draw() {
  mapa.Draw();

  for (auto &e : enemigos) {
    e->Dibujar();
  }

  for (auto &t : torres) {
    t->Dibujar();
  }

  for (auto &p : proyectiles) {
    p->Dibujar();
  }
}

void Game::ActualizarTorres() {
  for (auto &t : torres)
    t->atacar(enemigos);
}

void Game::ActualizarEnemigos() {
  for (size_t i = 0; i < enemigos.size();) {
    Enemy *e = enemigos[i].get();

    if (!e->estaVivo()) {
      if (e->hacerDanio()) {
        jugador.vida -= e->getDanio();
      } else {
        jugador.oro += e->getOro();
        EnemyDiedEvent ev;
        ev.gold = e->getOro();
        ev.position = {e->getX(), e->getY()};
        eventBus.publish(ev);
      }

      enemigos.erase(enemigos.begin() + i);
    } else {
      ++i;
    }
  }
}

void Game::ActualizarProyectiles() {
  for (size_t i = 0; i < proyectiles.size();) {
    Projectile *p = proyectiles[i].get();

    p->Actualizar();

    if (!p->EstaActivo()) {
      proyectiles.erase(proyectiles.begin() + i);
    } else {
      ++i;
    }
  }
}

void Game::GestionarInput() {
  if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
    Vector2 raton = GetMousePosition();

    int col = (int)(raton.x / TILE_SIZE);
    int fil = (int)(raton.y / TILE_SIZE);

    if (mapa.GetTipoCasilla(col, fil) == 0) {
      bool ocupado = false;
      for (auto &t : torres) {
        int tCol = (int)(t->getX() / TILE_SIZE);
        int tFil = (int)(t->getY() / TILE_SIZE);
        if (tCol == col && tFil == fil) {
          ocupado = true;
          break;
        }
      }

      if (!ocupado) {
        // Construcción deshabilitada hasta change de combate/economía
      } else {
        printf("¡Ya hay una torre ahí!\n");
      }
    } else {
      printf("No se puede construir en el camino.\n");
    }
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

Game::~Game() {}