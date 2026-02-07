"""
==========================================================
|  Archivo       : H_Maximal_AND.py
|  Autor         : Russell
|  Fecha         : 2026-02-07 17:35
|--------------------------------------------------------
|  Tópicos utilizados:
|  - bitsmas
|  - training
|  - *1300
==========================================================
"""

from typing import List
import sys

def gcd(a: int, b: int) -> int:
    """Máximo común divisor"""
    if a % b == 0:
        return b
    return gcd(b, a % b)

def floordiv(a: int, b: int) -> int:
    """División entera hacia abajo (estilo C++)"""
    if a >= 0:
        return a // b
    return -((-a + b - 1) // b)

def ceildiv(a: int, b: int) -> int:
    """División entera hacia arriba"""
    if a >= 0:
        return (a + b - 1) // b
    return -((-a) // b)

def bitlen_unsigned(n: int) -> int:
    """Equivalente a __builtin_clzll"""
    return 1 if n == 0 else n.bit_length()


def solve() -> None:
    n: int
    k: int
    n, k = map(int, sys.stdin.readline().split())
    a: List[int] = list(map(int, sys.stdin.readline().split()))

    # contar bits encendidos por posición
    bit_count: List[int] = [0] * 31
    for ai in a:
        for bit in range(30, -1, -1):
            if ai & (1 << bit):
                bit_count[bit] += 1

    ans: int = 0
    for bit in range(30, -1, -1):
        restante: int = n - bit_count[bit]
        if k >= restante:
            k -= restante
            ans |= (1 << bit)

    print(ans)


def main() -> None:
    # CASO MULTI-TEST
    t = int(sys.stdin.readline())
    for _ in range(t):
        solve()

    # CASO SINGLE-TEST
    # solve()

if __name__ == "__main__":
    main()