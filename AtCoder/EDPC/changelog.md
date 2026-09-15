# EDPC — Changelog

Registro cronológico del avance en el AtCoder Educational DP Contest.
Ver `notes.md` para el detalle conceptual (estado/transición) de cada problema.

## 2026-09-11

- **A - Frog 1**: resuelto e implementado en `A_Frog1.cpp`. Primer problema
  de la serie, dp 1D modelado como camino mínimo en un DAG (piedras = nodos,
  saltos = flechas con peso).
- **B - Frog 2**: resuelto e implementado en `B_Frog2.cpp`. Generalización
  de Frog 1 con salto de hasta K piedras (antes fijo en 2).
- **C - Vacation**: comentarios de estado/transición entregados en el chat
  (no el código, ya que a partir de este problema Russell resuelve el
  `solve()` por su cuenta y solo pide pistas). Primer problema donde el
  estado necesita una dimensión extra (día + última actividad) porque el
  índice de posición solo no identifica el estado. En el camino se discutió
  la dualidad prefijo (recorrer 1→N) vs sufijo (recorrer N→1) en DP.
  Implementación en curso.

## 2026-09-14

- Práctica de refuerzo del patrón de C - Vacation (estado extendido con
  "última elección") usando problemas de Codeforces:
  - **CF 1195C - Basketball Exercise** (1400): **AC**. Costó bastante
    encontrar la transición correcta — Russell propuso una versión con
    `dp[fila][i-1]`/`dp[fila][i-2]` (en vez de la versión "arrastrar" con
    `dp[i-1][misma fila]`), razonando que con alturas siempre positivas
    nunca hace falta saltear más de 1 columna. Se verificó a mano contra
    el ejemplo oficial (n=3, esperado 19) antes de programarlo, y dio AC.
    Insight clave para recordar: ese argumento depende de que los valores
    sean positivos; con valores negativos no aplicaría y haría falta la
    versión "arrastrar" (más general).
  - CF 698A - Vacations (1400): **AC** (resuelto antes que Basketball
    Exercise; corregido en este registro, se había anotado mal como
    pendiente).

## Próximo

- Terminar C - Vacation (AtCoder).
- Más práctica del patrón de estado extendido: CF 455A - Boredom, CF 219C - Color Stripe.
- D - Knapsack 1: https://atcoder.jp/contests/dp/tasks/dp_d
