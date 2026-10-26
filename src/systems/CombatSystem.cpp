#include "../../include/systems/CombatSystem.h"
#include "../../include/events/Event.h"

void CombatSystem::update(Game &game) {
  for (auto &t : game.getTorres())
    t->atacar(game.getEnemigos());

  auto &proyectiles = game.getProyectiles();
  for (size_t i = 0; i < proyectiles.size();) {
    Projectile *p = proyectiles[i].get();

    p->Actualizar();

    if (!p->EstaActivo()) {
      proyectiles.erase(proyectiles.begin() + i);
    } else {
      ++i;
    }
  }

  auto &enemigos = game.getEnemigos();
  for (size_t i = 0; i < enemigos.size();) {
    Enemy *e = enemigos[i].get();

    if (!e->estaVivo()) {
      if (e->hacerDanio()) {
        game.getJugador().vida -= e->getDanio();

        EnemyReachedEndEvent ev;
        ev.damage = e->getDanio();
        game.getEventBus().publish(ev);
      } else {
        game.getJugador().oro += e->getOro();
        EnemyDiedEvent ev;
        ev.gold = e->getOro();
        ev.position = {e->getX(), e->getY()};
        game.getEventBus().publish(ev);
      }

      enemigos.erase(enemigos.begin() + i);

      // Los proyectiles que iban hacia el enemigo borrado quedan sin
      // objetivo (evita puntero colgante en el siguiente frame)
      for (auto &pr : proyectiles) {
        if (pr->getObjetivo() == e) {
          pr->setObjetivo(nullptr);
        }
      }
    } else {
      ++i;
    }
  }
}
