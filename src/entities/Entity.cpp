#include "../../include/entities/Entity.h"

Vector2 Entity::calcularMovimiento(Vector2 posicion, Vector2 destino,
                                   float velocidad) {
  float delta = GetFrameTime();
  float paso = velocidad * delta;

  float distancia = Vector2Distance(destino, posicion);
  if (distancia <= paso) {
    return {destino.x, destino.y};
  } else {
    Vector2 direccion = Vector2Normalize(Vector2Subtract(destino, posicion));
    return {posicion.x + (direccion.x * paso),
            posicion.y + (direccion.y * paso)};
  }
}

void Entity::Dibujar() {
  // 1. FUENTE: Cogemos toda la imagen original (aunque sea gigante)
  Rectangle fuente = {0.0f, 0.0f, (float)renderable.texture.width,
                      (float)renderable.texture.height};

  // 2. TAMAÑO FINAL: Definimos cuánto queremos que mida en pantalla
  // Usamos TILE_SIZE (40) para que ocupe exactamente una casilla.
  // (Si quieres que sea un poco más pequeño que la casilla, pon TILE_SIZE *
  // 0.8f)
  float anchoFinal = (float)TILE_SIZE;
  float altoFinal = (float)TILE_SIZE;

  // 3. POSICIÓN: Dónde se va a dibujar
  Rectangle destino = {position.x, position.y, anchoFinal, altoFinal};

  // 4. EL CENTRADO (ORIGEN):
  // Le decimos a Raylib que el punto de anclaje es el CENTRO de la nueva
  // imagen. Al poner esto, Raylib coloca automáticamente el centro de la imagen
  // en tu (x,y).
  Vector2 origen = {anchoFinal / 2.0f, altoFinal / 2.0f};

  // 5. DIBUJAR
  DrawTexturePro(renderable.texture, fuente, destino, origen, 0.0f, WHITE);

  // DEBUG: Descomenta esto para ver si el punto rojo (tu x,y lógica) está en el
  // centro DrawCircle(x, y, 3, RED);
}

Entity::~Entity() {}
