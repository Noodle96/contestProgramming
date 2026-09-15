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

## Próximo

- Terminar C - Vacation.
- D - Knapsack 1: https://atcoder.jp/contests/dp/tasks/dp_d
