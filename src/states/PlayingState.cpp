#include "../../include/states/PlayingState.h"
#include "../../include/core/Game.h"

void PlayingState::update(Game &game) { game.Actualizar(); }
void PlayingState::draw(Game &game) { game.Draw(); }
void PlayingState::handleInput(Game &game) { game.GestionarInput(); }