#pragma once
#include <string>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

const int TILE_SIZE = 20;
const int COLS = SCREEN_WIDTH / TILE_SIZE;
const int ROWS = SCREEN_HEIGHT / TILE_SIZE;

const int FPS = 60;

// Cámara inclinada (2.5D): comprime el eje vertical para simular la vista
// inclinada y reduce ligeramente la escala de los sprites según la fila
// (profundidad) en la que están.
const float INCLINED_VERTICAL_SCALE = 0.85f;
const float INCLINED_DEPTH_SCALE_STEP = 0.015f;
const float INCLINED_DEPTH_SCALE_MIN = 0.70f;

// --- Catalogo central de assets -----------------------------------------
// <nombre> son ficheros dentro de ASSETS_DIR; carga exclusiva via
// IRenderer::loadTexture(assetPath(nombre)).
const std::string ASSETS_DIR = "assets";

inline std::string assetPath(const std::string &nombre) {
  return nombre.empty() ? ASSETS_DIR : ASSETS_DIR + "/" + nombre;
}

// Torres
const std::string TORRE_MAGO_ASSET = "torre_mago.png"; // TorreMago
const std::string TORRE_LANCERO_ASSET = "torre_lancero.png"; // TorreLancero
// Enemigos
const std::string GOBLIN_ASSET = "duende.png";
const std::string ORC_ASSET = "orco.png";
const std::string BOSS_ASSET = "mago_malvado.png";
// Proyectil
const std::string PROJECTILE_MAGO_ASSET = "proyectil.png"; // bola azul
const std::string PROJECTILE_LANCERO_ASSET = "lanza.png";  // lanza voladora
// Mapa: hierba base + variacion; camino liso; transiciones por lado
const std::string TILE_CESPED_ASSET = "tile_0000.png";
const std::string TILE_CESPED_VAR_ASSET = "tile_0001.png";
const std::string TILE_CAMINO_ASSET = "tile_0025.png";
const std::string TILE_FIN_CAMINO_IZQ_ASSET = "tile_0024.png";
const std::string TILE_FIN_CAMINO_DER_ASSET = "tile_0026.png";
const std::string TILE_FIN_CAMINO_ABAJO_ASSET = "tile_0037.png";
const std::string TILE_FIN_CAMINO_ARRIBA_ASSET = "tile_0040.png";
