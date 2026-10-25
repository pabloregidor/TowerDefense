#pragma once
enum TipoEnemigo { GOBLIN, ORC, BOSS };
enum TipoTorre { TORRE_MAGO, TORRE_LANCERO };

struct InfoOleada {
  TipoEnemigo tipo;
  int cantidad;
  float spawn;
};
