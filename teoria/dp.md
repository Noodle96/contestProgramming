# Programación Dinámica (DP)

## DP como camino mínimo/máximo en un grafo de estados (DAG)

**Problema relacionado:** A - Frog 1 (AtCoder Educational DP Contest) — https://atcoder.jp/contests/dp/tasks/dp_a

**Enunciado:** Hay N piedras en fila, cada una con una altura h_i. Una rana empieza en la piedra 1 y quiere llegar a la piedra N. Desde la piedra i puede saltar a i+1 o i+2, pagando un costo |h_i - h_j| donde j es la piedra de aterrizaje. Se pide el costo total mínimo para llegar a la piedra N.

**Demostración/intuición:** Toda DP se puede dibujar como un grafo dirigido: cada estado es un nodo, y cada transición `dp[estado_actual] = f(dp[estado_previo], costo)` es una flecha del estado previo al actual con ese costo. Si el grafo no tiene ciclos (un DAG, que es el caso siempre que el estado dependa solo de estados "anteriores" en algún orden, como el índice de un arreglo), entonces calcular `dp[i]` en orden creciente de i es exactamente lo mismo que calcular el camino mínimo (o máximo, según el problema) desde el nodo base hasta cada nodo, en el orden topológico del grafo. No hace falta Dijkstra ni nada más sofisticado porque el orden de los índices YA es un orden topológico válido.

En Frog 1: cada piedra i es un nodo, con flechas hacia i+1 e i+2 (si existen) de peso |h_i - h_j|. Dibujar ese grafo en papel (puntos + flechas con su peso) hace evidente la recurrencia sin necesidad de "adivinarla": a un nodo i solo le llegan flechas desde i-1 e i-2, así que dp[i] tiene que ser el mínimo entre esas dos opciones.

**Aplicación al problema:** con dp[0] = 0 (caso base, ya estamos ahí sin gastar nada):

```
dp[i] = min( dp[i-1] + |h[i]-h[i-1]|, dp[i-2] + |h[i]-h[i-2]| )   (si i >= 2)
dp[i] = dp[i-1] + |h[i]-h[i-1]|                                    (si i == 1)
```

La respuesta es dp[N-1] (0-indexado). Complejidad O(N), un solo recorrido de izquierda a derecha porque el grafo es un DAG con aristas únicamente "hacia adelante".

## Preguntas típicas de entrevistas

1. **¿Por qué se puede resolver una DP con un simple bucle en vez de un algoritmo de caminos mínimos como Dijkstra?** Porque el grafo de estados de una DP típica es un DAG (no tiene ciclos): cada estado depende solo de estados "anteriores". Recorrer los estados en un orden topológico válido (para arreglos, el orden creciente del índice) resuelve el camino mínimo/máximo en O(V+E) sin necesitar una cola de prioridad.

2. **¿Qué son "overlapping subproblems" y "optimal substructure", y por qué ambos son necesarios para aplicar DP?** Overlapping subproblems significa que la recursión ingenua recalcula el mismo subproblema muchas veces (de ahí el ahorro al cachear). Optimal substructure significa que la solución óptima global se construye combinando soluciones óptimas de subproblemas más chicos. Sin optimal substructure, memoizar no te da la respuesta correcta (aunque ahorre tiempo); sin overlapping subproblems, memoizar no ahorra nada (cada subproblema se visita una sola vez de todas formas).

3. **¿Cuál es la diferencia práctica entre memoización (top-down) y tabulación (bottom-up)?** La memoización es recursión normal con una caché; es más fácil de escribir porque el orden de evaluación lo decide la propia recursión, y solo calcula los estados que realmente se necesitan. La tabulación itera explícitamente en un orden donde las dependencias ya están resueltas; suele ser más rápida en la práctica (sin overhead de llamadas recursivas) y más fácil de optimizar en memoria (rolling array), pero requiere pensar el orden correcto de antemano.

4. **En Frog 1, ¿por qué dp[i] solo necesita mirar dp[i-1] y dp[i-2]?** Porque esas son las únicas aristas entrantes al nodo i en el grafo (solo se puede saltar 1 o 2 piedras hacia adelante). En general, el "abanico" de estados que hay que revisar en la transición es exactamente el conjunto de aristas entrantes al nodo en el grafo dibujado.

5. **¿Cómo se reconstruye el camino óptimo, no solo su costo?** Guardando, junto a cada dp[i], de qué estado vino (un array `padre[i]` con el nodo que dio el mínimo). Al final se retrocede desde el nodo final siguiendo los punteros `padre` hasta el nodo base, y se invierte la lista obtenida.

6. **¿Qué cambia si en vez de saltar a i+1 o i+2, la rana puede saltar hasta K piedras adelante (Frog 2)?** El grafo tiene más aristas por nodo (hasta K en vez de 2), así que la transición pasa de mirar 2 predecesores a mirar hasta K predecesores. La complejidad sube de O(N) a O(N*K), pero la idea (DAG + orden topológico = el propio índice) es idéntica.

7. **¿Cuándo NO sirve pensar una DP como un DAG simple recorrido en orden de índice?** Cuando el estado no tiene un orden de dependencia lineal obvio (por ejemplo, dp sobre subconjuntos/bitmask, donde el "orden topológico" es por tamaño creciente del conjunto, o dp sobre árboles, donde el orden es post-order del DFS). El principio del DAG sigue aplicando, pero el orden topológico ya no es "de menor a mayor índice".

8. **¿Por qué siempre conviene inicializar dp con un valor "infinito" en problemas de minimización?** Para representar estados inalcanzables sin confundirlos con un costo real de 0 o cualquier otro valor válido; así, al tomar un mínimo, un estado inalcanzable nunca "gana" por error frente a un estado sí alcanzable.
