#include "../../include/states/PreparacionState.h"
#include "../../include/core/Game.h"
#include "../../include/states/OleadaState.h"
#include "../../include/systems/CombatSystem.h"
#include "../../include/systems/MovementSystem.h"
#include "../../include/systems/RenderSystem.h"
#include <memory>

void PreparacionState::update(Game &game) {
  // Sin enemigos vivos entre oleadas; los sistemas van por inercia
  MovementSystem::update(game.getEnemigos(), GetFrameTime());
  CombatSystem::update(game);
}

void PreparacionState::draw(Game &game) {
  RenderSystem::draw(game);

  const char *msg = "ENTER o ESPACIO para iniciar la oleada";
  DrawText(msg, SCREEN_WIDTH / 2 - 160, SCREEN_HEIGHT - 60, 20, BLACK);
  DrawText("Preparacion", SCREEN_WIDTH / 2 - 60, 20, 20, BLACK);
  RenderSystem::drawHUD(game);
}

void PreparacionState::handleInput(Game &game) {
  if (IsKeyPressed(KEY_ONE)) {
    game.setTipoSeleccionado(1);
  } else if (IsKeyPressed(KEY_TWO)) {
    game.setTipoSeleccionado(2);
  } else if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE)) {
    game.getJugador().oleada++;
    game.CambiarEstado(std::make_unique<OleadaState>());
    return;
  }

  if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
    Vector2 raton = GetMousePosition();
    int col = (int)(raton.x / TILE_SIZE);
    int fil = (int)(raton.y / TILE_SIZE);
    game.ConstruirTorre(col, fil);
  }
}
