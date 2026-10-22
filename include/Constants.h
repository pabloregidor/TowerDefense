#pragma once

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

const int TILE_SIZE = 40;
const int COLS = SCREEN_WIDTH / TILE_SIZE;
const int ROWS = SCREEN_HEIGHT / TILE_SIZE;

const int FPS = 60;

// Cámara inclinada (2.5D): comprime el eje vertical para simular la vista
// inclinada y reduce ligeramente la escala de los sprites según la fila
// (profundidad) en la que están.
const float INCLINED_VERTICAL_SCALE = 0.85f;
const float INCLINED_DEPTH_SCALE_STEP = 0.015f;
const float INCLINED_DEPTH_SCALE_MIN = 0.70f;
