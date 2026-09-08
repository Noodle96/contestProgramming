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

### 6. Ejemplo numérico completo

#### Ejemplo A — verificando el Lema de la sección 3 (una transposición cualquiera cambia inv en cantidad impar)

Sea π = [1, 4, 2, 3] (posiciones 1..4). Inversiones de π:

| par (i,j) | valores | ¿inversión? |
|---|---|---|
| (2,3) | 4,2 | sí |
| (2,4) | 4,3 | sí |

inv(π) = 2 (par) → sgn(π) = (-1)² = +1.

Ahora aplicamos la transposición swap(p=1, q=4), es decir intercambiar los valores en las posiciones 1 y 4 (a = π(1) = 1, b = π(4) = 3). El resultado es π' = [3, 4, 2, 1].

Según la prueba del lema, el cambio total en inv se descompone en: el par (p,q) mismo, más un término por cada posición intermedia k ∈ {2,3}. Verifiquemos cada pieza con números reales:

- **k = 2, valor c = 4** (está *fuera* del rango [min(a,b), max(a,b)] = [1,3], porque 4 > 3):
  - Antes: pair(p,k) = (a=1, c=4) → 1>4 falso (0). pair(k,q) = (c=4, b=3) → 4>3 verdadero (1). Suma = 1.
  - Después: posición p ahora tiene b=3, posición q tiene a=1. pair(p,k) = (3,4) → falso (0). pair(k,q) = (4,1) → verdadero (1). Suma = 1.
  - **Cambio = 0** (par), como predice el caso "c fuera del rango".

- **k = 3, valor c = 2** (está *dentro* del rango [1,3], porque 1 < 2 < 3):
  - Antes: pair(p,k) = (1,2) → falso (0). pair(k,q) = (2,3) → falso (0). Suma = 0.
  - Después: pair(p,k) = (3,2) → verdadero (1). pair(k,q) = (2,1) → verdadero (1). Suma = 2.
  - **Cambio = +2** (par), como predice el caso "c dentro del rango" (con a<b).

- **Par (p,q) mismo**: antes (a=1,b=3) → 1>3 falso (0). Después (b=3 en p, a=1 en q) → 3>1 verdadero (1). **Cambio = +1** (impar).

Suma total de cambios = 0 + 2 + 1 = **3 (impar)**, tal como garantiza el lema, sin importar que p y q no sean adyacentes (distancia 3).

Comprobación directa contando inv(π') = [3,4,2,1]: los pares con inversión son (1,3), (1,4), (2,3), (2,4), (3,4) → inv(π') = 5. Efectivamente 5 - 2 = 3 (impar) ✓, y sgn(π') = (-1)⁵ = -1, que es exactamente -sgn(π): el signo se invirtió después de una sola transposición, tal como dice el Teorema de la sección 4.

#### Ejemplo B — aplicación al problema 911D (revertir un subarreglo)

Sea π = [2, 4, 1, 3, 5]. inv(π) = 3 (pares (1,3), (2,3), (2,4)) → paridad **impar**.

Consulta: revertir el subarreglo [l,r] = [2,4] (longitud L=3, valores 4,1,3 → revertidos 3,1,4). Resultado: π' = [2, 3, 1, 4, 5].

- Predicción: ⌊L/2⌋ = ⌊3/2⌋ = 1 transposición (solo swap(2,4); la posición central 3 queda fija). Como 1 es impar, la paridad **debe cambiar**.
- Comprobación directa: inv(π') = pares (1,3):(2,1) sí, (2,3):(3,1) sí → inv(π') = 2, paridad **par**.
- En efecto pasó de impar (3) a par (2) con una sola consulta, sin necesidad de recalcular todas las inversiones — solo bastaba saber que ⌊L/2⌋ = 1 es impar.

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
