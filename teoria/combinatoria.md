# Combinatoria y teoría de permutaciones

## Paridad de una permutación y conteo de inversiones

**Problema relacionado:** [911D - Inversion Counting](https://codeforces.com/contest/911/problem/D)
**Referencia:** [Wikipedia - Parity of a permutation](https://en.wikipedia.org/wiki/Parity_of_a_permutation)

### 1. Transposiciones y descomposición

Una **transposición** es una permutación que intercambia exactamente dos elementos y deja el resto fijo.

**Teorema (descomposición).** Toda permutación σ de {1, ..., n} puede escribirse como composición (producto) de transposiciones.

*Idea de la prueba:* por inducción. Si σ no es la identidad, existe una posición i con σ(i) ≠ i. Componiendo σ con la transposición (i, σ⁻¹(i)) se fija un elemento más. Repitiendo, en a lo más n-1 pasos se llega a la identidad, así que σ es producto de esas mismas transposiciones (en orden inverso).

Esta descomposición **no es única** (hay muchas formas de llegar a la misma permutación con distinto número de swaps), pero eso no importa para lo que sigue.

### 2. El signo está bien definido

**Teorema (invariante de paridad).** Aunque la descomposición en transposiciones no es única, la *paridad* del número de transposiciones usado sí lo es: o todas las descomposiciones de σ usan un número par de transposiciones, o todas usan un número impar.

Esto permite definir sgn(σ) = (-1)^k, donde k es el número de transposiciones de *cualquier* descomposición de σ. sgn es un homomorfismo de grupo S_n → {+1, -1}.

*Idea de la prueba (vía polinomio de Vandermonde):* se define
Δ(x₁, ..., xₙ) = ∏_{i<j} (xᵢ - xⱼ)

Al aplicar una permutación σ reordenando las variables, cada transposición cambia exactamente el signo de un factor (xᵢ - xⱼ) → (xⱼ - xᵢ), multiplicando Δ por -1. Como el resultado final σ(Δ) = sgn(σ)·Δ no depende de cómo se descompuso σ, la cantidad de cambios de signo (mod 2) tampoco puede depender de la descomposición elegida.

### 3. Lema clave: una transposición cualquiera cambia la paridad de inversiones

Una **inversión** en una permutación π es un par de posiciones (i, j) con i < j pero π(i) > π(j). Sea inv(π) el número de inversiones.

**Lema.** Intercambiar los valores en dos posiciones cualesquiera p < q (no necesariamente adyacentes) cambia inv(π) en una cantidad **impar** (nunca par).

*Prueba.* Sean a = π(p), b = π(q). Los pares que no involucran a p ni a q no cambian. Quedan dos tipos de pares afectados:

- El par (p, q) mismo: cambia su estado de inversión exactamente una vez (de inversión a no-inversión o viceversa) → contribuye ±1 (impar).
- Para cada posición intermedia k con p < k < q, con valor c = π(k): se puede verificar por casos (según si c está entre a y b, o fuera de ese rango) que la suma de los estados de los pares (p,k) y (k,q) cambia en 0 o ±2, es decir, siempre en una cantidad **par**.

Sumando: cambio total = (impar del par (p,q)) + (suma de cambios pares de las posiciones intermedias) = impar. ∎

Este lema es más fuerte que decir "un swap adyacente cambia la paridad en ±1": vale para *cualquier* transposición, sin importar la distancia entre p y q.

### 4. Teorema: sgn(π) = (-1)^inv(π)

Partiendo de la identidad (inv = 0, sgn = +1) y aplicando transposiciones una a una para llegar a π:

- Cada transposición cambia sgn en un factor -1 (por definición de sgn).
- Cada transposición cambia inv(π) en una cantidad impar (por el lema), es decir, cambia la *paridad* de inv en cada paso.

Como ambos cambian de paridad exactamente una vez por cada transposición aplicada, después de k transposiciones ambos coinciden: sgn(π) = (-1)^k = (-1)^inv(π). Como esto vale para cualquier π alcanzable (todas lo son, por el teorema de descomposición), la igualdad es general.

**Conclusión:** la paridad del número de inversiones de una permutación es invariante bajo cualquier transposición — sube o baja en 1 (mod 2) sin importar qué par de posiciones se intercambie.

### 5. Aplicación al problema 911D

El problema da una permutación inicial y m consultas, cada una revierte (reverse) un subarreglo [l, r], y pide la paridad de inv(π) después de cada consulta.

- Revertir el subarreglo [l, r] de longitud L = r - l + 1 equivale a aplicar exactamente ⌊L/2⌋ transposiciones: swap(l, r), swap(l+1, r-1), ..., hasta llegar al centro (si L es impar, el elemento central queda fijo y no cuenta).
- Por el lema de la sección 3, cada una de esas transposiciones cambia la paridad de inv(π). Por lo tanto, aplicar la consulta cambia la paridad global si y solo si ⌊L/2⌋ es impar.
- Algoritmo:
  1. Calcular la paridad inicial de inv(π) (por fuerza bruta O(n²), o con BIT/merge sort en O(n log n)).
  2. Por cada consulta (l, r): si ⌊(r-l+1)/2⌋ es impar, invertir (flip) la paridad guardada; si es par, no cambia.
  3. Responder "odd"/"even" según la paridad actual.
- Complejidad total: O(n² + m) (o O(n log n + m) con conteo de inversiones eficiente). No hace falta reconstruir el arreglo ni recalcular inversiones en cada consulta — solo contar transposiciones.

**Idea central para reconocer este patrón en otros problemas:** cuando una operación se puede descomponer en un número conocido de transposiciones, la paridad de inversiones cambia si y solo si ese número es impar. No hace falta rastrear el arreglo completo, solo la paridad.

---

## Preguntas típicas de entrevistas

**P: ¿Cómo determinarías si un rompecabezas deslizante (15-puzzle) es resoluble desde una configuración dada?**
R: Se calcula la paridad de la permutación de las fichas (ignorando el espacio vacío). Un estado es resoluble si y solo si su paridad coincide con la del estado objetivo, ajustando por la fila del espacio vacío en el caso de tableros con número par de columnas. Es una aplicación directa de que el signo de una permutación es invariante.

**P: Dado un arreglo, ¿cómo cuentas el número de inversiones en O(n log n)?**
R: Con merge sort modificado (contar inversiones al hacer el merge) o con un Binary Indexed Tree (Fenwick tree) recorriendo el arreglo y consultando cuántos elementos mayores ya se insertaron a la izquierda.

**P: ¿Por qué el signo de una permutación está bien definido si su descomposición en transposiciones no es única?**
R: Porque aunque el número de transposiciones varía, su paridad no — se puede probar con el polinomio de Vandermonde (cada transposición invierte el signo del producto ∏(xᵢ-xⱼ)) o mostrando que coincide con la paridad del número de inversiones.

**P: ¿Cómo diseñarías una estructura de datos que soporte revertir un rango del arreglo y responder la paridad de inversiones en tiempo sublineal?**
R: No hace falta rastrear el arreglo completo: basta con mantener un solo bit de paridad global y, en cada consulta de reversa de rango [l, r], hacer flip del bit si ⌊(r-l+1)/2⌋ es impar. Cada consulta es O(1).

**P: ¿Qué relación hay entre el número de inversiones y qué tan "ordenado" está un arreglo?**
R: El número de inversiones es 0 si y solo si el arreglo está ordenado, y es máximo (n(n-1)/2) si está en orden inverso. Es una métrica estándar de "distancia" a estar ordenado, y es la base de la complejidad de bubble sort y insertion sort (ambos son Θ(inversiones) comparaciones/swaps en el peor caso).

**P: Si solo puedes hacer swaps de elementos adyacentes, ¿cuál es el mínimo número de swaps para ordenar un arreglo?**
R: Exactamente el número de inversiones del arreglo, porque cada swap adyacente cambia el conteo de inversiones en exactamente ±1, y se necesita llegar a 0 inversiones.
