#pragma once
#include "../Constants.h"
#include "../raylib.h"
#include <vector>

class Map {
private:
  int grid[ROWS][COLS];
  std::vector<Vector2> camino;

public:
  // nivel: 1..3; cada nivel construye un layout/camino distinto
  explicit Map(int nivel = 1);
  void Draw();
  std::vector<Vector2> *GetCaminoPtr() { return &camino; };
  int GetTamCamino() const { return camino.size(); }
  int GetTipoCasilla(int col, int fil);
  ~Map();

private:
  void construir(int nivel);
};
