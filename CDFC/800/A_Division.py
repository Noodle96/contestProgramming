"""
==========================================================
|  Archivo       : A_Division.py
|  Autor         : Russell
|  Fecha         : 2026-02-07 23:03
|--------------------------------------------------------
|  Tópicos utilizados:
|  - implementation
|  - training
|  - *800
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
    ranking: int = int(sys.stdin.readline())
    ans: str = "Division "
    number: int
    if(ranking <= 1399 ):
        number = 4
    elif(ranking <= 1599):
        number = 3
    elif ranking <= 1899:
        number = 2
    else:
        number= 1

    print(ans + str(number))


def main() -> None:
    # CASO MULTI-TEST
    t = int(sys.stdin.readline())
    for _ in range(t):
        solve()

    # CASO SINGLE-TEST
    # solve()

if __name__ == "__main__":
    main()