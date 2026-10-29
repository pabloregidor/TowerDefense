# 🏰 tower-defense

Videojuego de Tower Defense en **C++17** con **raylib**: coloca torres, defiende el camino de 3 tipos de enemigos y sobrevive 3 niveles con 5 oleadas cada uno, con un Boss final.

## 🎮 Características

- **2 torres** (Torre Mago que lanza proyectiles, Torre Lancero de alcance corto), colocables sobre el césped con coste en oro
- **3 enemigos** (Goblin, Orco y Boss), cada uno con vida/velocidad/daño propios; oleadas configuradas por tipo y cantidad
- **3 niveles** con caminos distintos (mapas por tiles)
- Economía: oro (recompensa por baja), vida (pierdes si un enemigo llega al final), puntuación
- Render **2.5D**: vista inclinada que comprime el eje vertical y escala los sprites según la profundidad
- Estados de juego: **Preparación → Oleada → Transición de nivel → Victoria/Derrota**

## 🏗️ Arquitectura

Separación en capas con patrones de diseño:

| Capa | Contenido |
|---|---|
| `entities/` | Entity → Tower/Enemy/Projectile y sus subtipos |
| `factories/` | EnemyFactory, TowerFactory, ProjectileFactory |
| `systems/` | RenderSystem, MovementSystem, CombatSystem (lógica por frames) |
| `states/` | IGameState + 5 estados (State pattern con delegación update/draw/handleInput) |
| `events/` | EventBus con eventos tipados (EnemyDied, EnemyReachedEnd, WaveCompleted, TowerShoot…) |
| `rendering/` | Interfaz `IRenderer` + implementación RaylibRenderer (motor desacoplado de la lógica) |
| `core/` | Game, Map (grid + camino por nivel), PlayerStats, Oleadas |

El Event Bus desacopla lógica y presentación: los sistemas publican eventos (`EnemyDiedEvent` → oro/reward, `WaveCompletedEvent` → siguiente oleada…) y los estados suscriben.

## 🛠️ Tecnologías

- **C++17** con `g++`, sin frameworks de juego: solo **raylib** para render/ventana/input
- Gama de tiles y sprites PNG propios en `assets/` (38 ficheros)
- `lib/libraylib.a` incluida para compilar en Linux sin instalar nada; en macOS usa la de Homebrew

## 🚀 Compilación y ejecución

```bash
make run     # compila a build/tower_defense y arranca
make clean   # limpia objetos
```

Controles: en fase de preparación eliges torre (1=Mago, 2=Lancero) y la colocas clicando el césped.

## 📁 Estructura

```
src/         .cpp de entidades, sistemas, estados, factorías y core
include/     cabeceras orgánicas por módulo + raylib embebido
assets/      sprites y tiles del juego
lib/         raylib precompilada (Linux)
Makefile     build con g++ (detecta macOS y usa Homebrew raylib)
```
