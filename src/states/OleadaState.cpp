#include "../../include/states/OleadaState.h"
#include "../../include/core/Game.h"
#include "../../include/systems/CombatSystem.h"
#include "../../include/systems/MovementSystem.h"
#include "../../include/systems/RenderSystem.h"

void OleadaState::update(Game &game) {
  if (!iniciado) {
    iniciado = true;
    int n = game.getJugador().nivel;  // nivel 1..3
    int w = game.getJugador().oleada; // oleada 1..5
    restantes = 5 + 2 * (w - 1) + 3 * (n - 1);
    bool oleadaJefe0 = (n == 3 && w == 5);
    if (oleadaJefe0)
      restantes++; // el jefe no parte de la cuota de la formula
  }

  MovementSystem::update(game.getEnemigos(), GetFrameTime());
  CombatSystem::update(game);

  timerSpawn -= GetFrameTime();
  if (restantes > 0 && timerSpawn <= 0.0f) {
    // Tipo de enemigo: en la oleada final del nivel 3, el 6o spawn es
    // el jefe y hay 5 goblins de escolta al principio; el resto
    // alternan goblin y orc.
    TipoEnemigo tipo;
    bool oleadaJefe =
        (game.getJugador().nivel == 3 && game.getJugador().oleada == 5);

    if (oleadaJefe && spawnados == 5) {
      tipo = BOSS;
    } else if (spawnados % 3 == 2 && !oleadaJefe) {
      tipo = ORC;
    } else {
      tipo = GOBLIN;
    }

    game.SpawnEnemy(tipo);
    spawnados++;
    restantes--;

    timerSpawn = 1.0f;
  }
}

void OleadaState::draw(Game &game) {
  RenderSystem::draw(game);
  DrawText("Oleada en curso", SCREEN_WIDTH / 2 - 70, 20, 20, BLACK);
}

void OleadaState::handleInput(Game &game) { (void)game; }
