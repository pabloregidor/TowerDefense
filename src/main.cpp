#include "../include/Constants.h"
#include "../include/core/Game.h"
#include "../include/raylib.h"

int main() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tower Defense C++");
  SetTargetFPS(FPS);

  Game game;
  while (!WindowShouldClose()) {
    // Delegacion en el estado actual: update/draw/handleInput
    game.Actualizar();
    game.GestionarInput();
    BeginDrawing();
    ClearBackground(RAYWHITE);
    game.Draw();
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
