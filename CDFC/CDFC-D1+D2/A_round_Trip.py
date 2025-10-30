# ==========================================================
# |  Archivo       : A_round_trip.py
# |  Autor         : Russell
# |  Fecha         : 2025-10-30
# |---------------------------------------------------------
# |  Tópicos utilizados:
# |  - div1+div2
# ==========================================================
# python3 A_round_Trip.py < input.txt > output.txt

from __future__ import annotations
from typing import Iterator, List
import sys
import time

USE_SINGLE_CASE: bool = True
INF: int = 10**9

def gcd(a: int, b: int) -> int:
    """
    Máximo común divisor (versión recursiva).
    Equivalente a std::gcd, pero escrita a mano para plantillas.
    """
    if b == 0:
        return a
    return gcd(b, a % b)

def binary_exponentiation(base: int, exp: int) -> int:
    """
    Exponenciación binaria sin módulo.
    Complejidad: O(log exp).
    """
    result: int = 1
    while exp > 0:
        if exp % 2 == 1:       # si el bit actual de exp es 1, acumulamos
            result *= base
        base *= base            # avanzamos al siguiente bit (base^2, base^4, ...)
        exp //= 2
    return result

def floordiv(a: int, b: int) -> int:
    """
    floor(a/b) con la misma intención del helper C++ dado.
    Nota: en Python, '//' ya es floor; esta versión replica el snippet original.
    """
    if a >= 0:
        return a // b
    return - ((-a + b - 1) // b)

def ceildiv(a: int, b: int) -> int:
    """
    ceil(a/b) = -floor((-a)/b).
    Replica la lógica del helper del C++.
    """
    if a >= 0:
        return (a + b - 1) // b
    return - ((-a) // b)

def bitlen_unsigned(n: int) -> int:
    """
    Longitud en bits de un entero no negativo.
    Para n == 0 devolvemos 1 (como 64 - __builtin_clzll(0) en el helper original).
    """
    return 1 if n == 0 else n.bit_length()

_start_time: float = time.perf_counter()

def get_current_time() -> float:
    """
    Devuelve segundos transcurridos desde el arranque del programa.
    Similar a (clock() - startTime) / CLOCKS_PER_SEC en C++.
    """
    return time.perf_counter() - _start_time

# ----------------------------------------------------------
# Lógica del problema
# ----------------------------------------------------------

def solve_one(tokens_iter: Iterator[str]) -> str:
    """
    Procesa UN caso de prueba.

    Entrada esperada del iterador:
      R X D n
      s          (cadena de '0' y '1' de longitud n)

    Regla:
    - Si la ronda es div1 ('1') → rated siempre.
    - Si la ronda es div2 ('0') → rated solo si R < X.
    - Tras cada ronda rated, el rating R puede moverse a cualquier valor en [R-D, R+D].
      La estrategia es moverse lo más cerca posible de X-1 dentro de ese rango (con piso en 0).

    Retorna:
      Línea con el número de rondas 'rated' para este caso, seguida de '\n'.
    """
    # Leer cabecera del caso
    R: int = int(next(tokens_iter))
    X: int = int(next(tokens_iter))
    D: int = int(next(tokens_iter))
    n: int = int(next(tokens_iter))
    s: str = next(tokens_iter)

    def update_R(Rcur: int) -> int:
        """
        Dado el rating actual Rcur y el rango permitido [Rcur-D, Rcur+D],
        devuelve el nuevo rating siguiendo la estrategia:
        - objetivo 'target' = max(0, X-1)
        - clamp de 'target' a [lo, hi] con lo = max(0, Rcur-D), hi = Rcur+D
        """
        lo: int = max(0, Rcur - D)
        hi: int = Rcur + D
        target: int = X - 1
        if target < 0:
            target = 0
        if target < lo:
            return lo
        if target > hi:
            return hi
        return target

    rated: int = 0
    for c in s:
        if c == '1':
            # div1 (rated para todos)
            rated += 1
            R = update_R(R)
        else:
            # div2 (rated solo para R < X)
            if R < X:
                rated += 1
                R = update_R(R)
            # si R >= X: unrated → no cambia R

    return f"{rated}\n"

def main() -> None:
    """
    Punto de entrada:
    - Tokeniza toda la entrada estándar.
    - Si USE_SINGLE_CASE es False, asume formato con 't' al inicio (multi-caso).
    - Si USE_SINGLE_CASE es True, procesa exactamente un caso con los 5 tokens (R X D n s).
    - Acumula las salidas y las escribe al final (rápido y limpio).
    """
    data: List[str] = sys.stdin.read().strip().split()
    if not data:
        return

    it: Iterator[str] = iter(data)

    if USE_SINGLE_CASE:
        # Modo sin 't': exactamente un caso
        t: int = 1
    else:
        # Modo con 't': el primer token es el número de casos
        t: int = int(next(it))

    out_parts: List[str] = []
    for _ in range(t):
        out_parts.append(solve_one(it))

    sys.stdout.write("".join(out_parts))

if __name__ == "__main__":
    main()
