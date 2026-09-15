# EDPC — Notas de progreso

Notas de estudio para el AtCoder Educational DP Contest (A → Z). El enfoque:
modelar cada problema a lápiz y papel como un grafo de estados (nodos +
flechas con peso) antes de escribir código. Un problema por vez.

Contest: https://atcoder.jp/contests/dp

---

## Conceptos generales (van acumulándose con cada problema)

- **DP = camino mínimo/máximo en un DAG de estados.** Cada estado es un nodo,
  cada transición es una flecha con costo. Si el grafo no tiene ciclos, no
  hace falta Dijkstra: basta recorrer los nodos en un orden topológico
  válido (para arreglos indexados por posición, el propio orden creciente
  del índice ya lo es).
- **El orden de recorrido depende de cómo se define `dp[i]`, no es una regla
  fija.** Si `dp[i]` significa "lo mejor acumulado HASTA i" (prefijo),
  depende del pasado y se recorre de 1 a N. Si se redefine como "lo mejor
  posible DESDE i hasta el final" (sufijo), depende del futuro y se
  recorre de N a 1. Son formulaciones espejo del mismo problema — surgió
  discutiéndolo en Vacation (C).
- **Cuando el índice solo no alcanza para identificar el estado, hay que
  extender el estado.** En Frog (A, B) el nodo era solo "la piedra i". En
  Vacation (C) la restricción depende de qué actividad se eligió el día
  anterior, así que el estado pasó a ser `(día, última actividad)` — el
  grafo se vuelve "en capas" (varias filas por columna) en vez de una sola
  fila.

---

## A - Frog 1

- **Link:** https://atcoder.jp/contests/dp/tasks/dp_a
- **Archivo:** `A_Frog1.cpp`
- **Tópico(s):** dp 1D, camino mínimo en un DAG
- **Estado:** `dp[i]` = costo mínimo para llegar del nodo 0 al nodo i.
- **Grafo:** cada piedra i tiene flecha hacia i+1 e i+2 (si existen), peso
  `|h[i]-h[j]|`.
- **Transición:** `dp[i] = min(dp[i-1] + |h[i]-h[i-1]|, dp[i-2] + |h[i]-h[i-2]|)`
- **Caso base:** `dp[0] = 0`.
- **Complejidad:** O(N).
- **Estado:** resuelto e implementado.

## B - Frog 2

- **Link:** https://atcoder.jp/contests/dp/tasks/dp_b
- **Archivo:** `B_Frog2.cpp`
- **Tópico(s):** dp 1D, camino mínimo en un DAG
- **Estado:** `dp[i]` = costo mínimo para llegar del nodo 0 al nodo i.
- **Grafo:** igual que Frog 1, pero cada piedra i tiene flecha hacia
  i+1, i+2, ..., i+K (K es dato de entrada, ya no fijo en 2).
- **Transición:** `dp[i] = min( dp[i-j] + |h[i]-h[i-j]| )` para `j` de 1 a K
  (los que no se salgan del arreglo).
- **Caso base:** `dp[0] = 0`.
- **Complejidad:** O(N*K).
- **Estado:** resuelto e implementado.

## C - Vacation

- **Link:** https://atcoder.jp/contests/dp/tasks/dp_c
- **Archivo:** `C_Vacation.cpp`
- **Tópico(s):** dp con estado extendido, dp 1D
- **Estado:** `dp[i][X]` = felicidad máxima acumulada hasta el día i,
  terminando el día i con la actividad X (X en {A, B, C}).
- **Grafo:** en capas — N columnas (días), 3 nodos por columna (A,B,C).
  Flecha de `(i, X)` a `(i+1, Y)` para toda `Y != X` (no se puede repetir
  actividad en días consecutivos).
- **Transición:** `dp[i][A] = a_i + max(dp[i-1][B], dp[i-1][C])` (análogo
  para B y C, siempre excluyendo la propia fila del día anterior).
- **Caso base:** día 0 sin restricción previa: `dp[0][X] = valor de X ese día`.
- **Respuesta:** `max(dp[N-1][A], dp[N-1][B], dp[N-1][C])`.
- **Complejidad:** O(N) (3 estados por día, transición O(1)).
- **Lección clave:** primer problema donde el índice de posición solo no
  alcanza como estado; hubo que agregarle una dimensión.
- **Estado:** planteado (comentarios/estado listos), en proceso de
  implementación por Russell.

## D - Knapsack 1 (siguiente)

- **Link:** https://atcoder.jp/contests/dp/tasks/dp_d
- **Estado:** pendiente.
