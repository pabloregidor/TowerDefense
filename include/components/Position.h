#pragma once
#include "../raylib.h"

// Posición lógica de la entidad (el nombre Transform colisiona con
// la estructura Transform de raylib.h)
struct Position {
  float x = 0.0f;
  float y = 0.0f;
};
