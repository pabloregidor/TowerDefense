#include "../../include/core/Map.h"

namespace {

// Marca una fila horizontal de casillas de camino (cols incluidos)
void marcaFila(int grid[ROWS][COLS], int fil, int colIni, int colFin) {
  for (int c = colIni; c <= colFin; c++) {
    grid[fil][c] = 1;
  }
}

// Marca una columna vertical de casillas de camino (filas incluidas)
void marcaColumna(int grid[ROWS][COLS], int col, int filIni, int filFin) {
  int paso = (filIni <= filFin) ? 1 : -1;
  for (int f = filIni; paso > 0 ? f <= filFin : f >= filFin; f += paso) {
    grid[f][col] = 1;
  }
}

Vector2 centroCasilla(int col, int fil) {
  return Vector2{(float)(col * TILE_SIZE + TILE_SIZE / 2),
                 (float)(fil * TILE_SIZE + TILE_SIZE / 2)};
}

void limpiarGrid(int grid[ROWS][COLS]) {
  for (int i = 0; i < ROWS; i++)
    for (int j = 0; j < COLS; j++)
      grid[i][j] = 0;
}

} // namespace

Map::Map(int nivel, IRenderer *r) : renderer(r), seed(nivel * 7919) {
  if (renderer != nullptr) {
    tileCesped    = renderer->loadTexture(assetPath(TILE_CESPED_ASSET));
    tileCespedVar = renderer->loadTexture(assetPath(TILE_CESPED_VAR_ASSET));
    tileCamino    = renderer->loadTexture(assetPath(TILE_CAMINO_ASSET));
  }
  construir(nivel);
}

void Map::construir(int nivel) {
  limpiarGrid(grid);
  camino.clear();

  // Nivel 1: zigzag básico (el camino original del juego)
  if (nivel == 1) {
    marcaFila(grid, 2, 0, 10);
    marcaColumna(grid, 10, 2, 12);
    marcaFila(grid, 12, 10, COLS - 1);

    camino.push_back(Vector2{0, (float)(2 * TILE_SIZE + TILE_SIZE / 2)});
    camino.push_back(centroCasilla(10, 2));
    camino.push_back(centroCasilla(10, 12));
    camino.push_back(Vector2{(float)SCREEN_WIDTH,
                             (float)(12 * TILE_SIZE + TILE_SIZE / 2)});
  }
  // Nivel 2: camino con U invertida; baja, cruza y vuelve a subir
  else if (nivel == 2) {
    marcaFila(grid, 5, 0, 5);
    marcaColumna(grid, 5, 5, 10);
    marcaFila(grid, 10, 5, 14);
    marcaColumna(grid, 14, 10, 5);
    marcaFila(grid, 5, 14, COLS - 1);

    camino.push_back(Vector2{0, (float)(5 * TILE_SIZE + TILE_SIZE / 2)});
    camino.push_back(centroCasilla(5, 5));
    camino.push_back(centroCasilla(5, 10));
    camino.push_back(centroCasilla(14, 10));
    camino.push_back(centroCasilla(14, 5));
    camino.push_back(Vector2{(float)SCREEN_WIDTH,
                             (float)(5 * TILE_SIZE + TILE_SIZE / 2)});
  }
  // Nivel 3: serpiente larga que baja al final
  else {
    marcaFila(grid, 1, 0, 15);
    marcaColumna(grid, 15, 1, 13);
    marcaFila(grid, 13, 15, COLS - 1);

    camino.push_back(Vector2{0, (float)(1 * TILE_SIZE + TILE_SIZE / 2)});
    camino.push_back(centroCasilla(15, 1));
    camino.push_back(centroCasilla(15, 13));
    camino.push_back(Vector2{(float)SCREEN_WIDTH,
                             (float)(13 * TILE_SIZE + TILE_SIZE / 2)});
  }
}

void Map::Draw() {
  for (int y = 0; y < ROWS; y++) {
    for (int x = 0; x < COLS; x++) {
      int posX = x * TILE_SIZE;
      int posY = y * TILE_SIZE;

      // base opaca para tapar marcas de borde/alpha de los tiles Kenney
      DrawRectangle(posX, posY, TILE_SIZE, TILE_SIZE,
                    grid[y][x] != 0 ? DARKBROWN : DARKGREEN);

      if (renderer != nullptr) {
        const Texture2D &tile =
            (grid[y][x] != 0)
                ? tileCamino
                : ((x * 13 + y * 7 + seed) % 11 == 0 ? tileCespedVar
                                                     : tileCesped);
        renderer->drawTexture(tile, (float)posX + TILE_SIZE / 2.0f,
                              (float)posY + TILE_SIZE / 2.0f,
                              (float)TILE_SIZE, (float)TILE_SIZE, false);
      }
      // sin renderer: solo queda el rect de color (fallback)
    }
  }

  for (Vector2 punto : camino) {
    DrawCircleV(punto, 5, RED);
  }
}

int Map::GetTipoCasilla(int col, int fil) {
  if (col < 0 || col >= COLS || fil < 0 || fil >= ROWS)
    return -1;
  return grid[fil][col];
}

Map::~Map() {};
