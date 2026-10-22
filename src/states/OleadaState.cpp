#include "../../include/states/OleadaState.h"
#include "../../include/core/Game.h"
#include "../../include/events/Event.h"
#include "../../include/states/DerrotaState.h"
#include "../../include/states/PreparacionState.h"
#include "../../include/states/TransicionState.h"
#include "../../include/states/VictoriaState.h"
#include "../../include/systems/CombatSystem.h"
#include "../../include/systems/MovementSystem.h"
#include "../../include/systems/RenderSystem.h"
#include <memory>

void OleadaState::update(Game &game) {
  if (!iniciado) {
    iniciado = true;
    int n = game.getJugador().nivel;  // nivel 1..3
    int w = game.getJugador().oleada; // oleada 1..5
    restantes = 5 + 2 * (w - 1) + 3 * (n - 1);
    if (n == 3 && w == 5) {
      restantes++; // el jefe no parte de la cuota de la formula
    }
    game.setDanioEnOleada(false);
  }

  MovementSystem::update(game.getEnemigos(), GetFrameTime());
  CombatSystem::update(game);

  if (game.getJugador().vida <= 0) {
    game.CambiarEstado(std::make_unique<DerrotaState>());
    return;
  }

  timerSpawn -= GetFrameTime();
  if (restantes > 0 && timerSpawn <= 0.0f) {
    // Tipo de enemigo: en la oleada final del nivel 3 el 6o spawn es el
    // jefe; los 5 primeros son goblins de escolta y el resto alternan.
    TipoEnemigo tipo;
    bool oleadaJefe =
        (game.getJugador().nivel == 3 && game.getJugador().oleada == 5);

    if (oleadaJefe && spawnados == 5) {
      tipo = BOSS;
    } else if (spawnados % 3 == 2) {
      tipo = ORC;
    } else {
      tipo = GOBLIN;
    }

    game.SpawnEnemy(tipo);
    spawnados++;
    restantes--;

    timerSpawn = 1.0f;
  }

  // Oleada completa: cuota agotada y sin enemigos vivos
  if (restantes == 0 && game.getEnemigos().empty()) {
    PlayerStats &p = game.getJugador();
    bool perfect = !game.haRecibidoDanio();

    WaveCompletedEvent ev;
    ev.level = p.nivel;
    ev.wave = p.oleada;
    ev.perfect = perfect;
    game.getEventBus().publish(ev);

    if (perfect) {
      p.oro += 50;
      p.points += 100;
    }

    if (p.oleada == 5) {
      if (p.nivel < 3) {
        game.CambiarEstado(std::make_unique<TransicionState>());
      } else {
        game.CambiarEstado(std::make_unique<VictoriaState>());
      }
    } else {
      game.CambiarEstado(std::make_unique<PreparacionState>());
    }
  }
}

void OleadaState::draw(Game &game) {
  RenderSystem::draw(game);
  DrawText("Oleada en curso", SCREEN_WIDTH / 2 - 70, 20, 20, BLACK);
  RenderSystem::drawHUD(game);
}

void OleadaState::handleInput(Game &game) { (void)game; }
