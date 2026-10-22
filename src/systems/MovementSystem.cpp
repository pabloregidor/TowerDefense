#include "../../include/systems/MovementSystem.h"

void MovementSystem::update(std::vector<std::unique_ptr<Enemy>> &enemies,
                           float dt) {
  (void)dt;
  for (auto &e : enemies) {
    if (e && e->estaVivo()) {
      e->caminar();
    }
  }
}