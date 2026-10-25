#pragma once
#include "../Constants.h"
#include "../raylib.h"
#include "../rendering/IRenderer.h"
#include <vector>

class Map {
private:
  int grid[ROWS][COLS];
  std::vector<Vector2> camino;

public:
  // nivel: 1..3; cada nivel construye un layout/camino distinto
  explicit Map(int nivel = 1, IRenderer *renderer = nullptr);
  void Draw();
  std::vector<Vector2> *GetCaminoPtr() { return &camino; };
  int GetTamCamino() const { return camino.size(); }
  int GetTipoCasilla(int col, int fil);
  ~Map();

private:
  void construir(int nivel);
  IRenderer *renderer = nullptr;
  Texture2D tileCesped{};
  Texture2D tileCespedVar{};
  Texture2D tileCamino{};
  int seed = 0;
};
