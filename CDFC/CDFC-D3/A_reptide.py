"""
==========================================================
|  Archivo       : A_reptide.py
|  Autor         : Russell
|  Fecha         : 2026-08-12 15:21
|--------------------------------------------------------
|  Tópicos utilizados:
|  - sorting
|  - training
|  - Div 3
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
    # leer una lista de enteros
    arr: List[int] = list(map(int, sys.stdin.readline().split()))
    arr.sort()
    ans: int = min(arr[1]-  arr[0], arr[2]-  arr[1])
    print(ans)
    # data = sys.stdin.readline().split()
    # if not data:
        # return
    # n: int = int(data[0])
    # arr: List[int] = list(map(int, sys.stdin.readline().split()))
    # print(n)
    # print(" ".join(map(str, arr)))


def main() -> None:
    # CASO MULTI-TEST
    t = int(sys.stdin.readline())
    for _ in range(t):
        solve()

    # CASO SINGLE-TEST
    # solve()

if __name__ == "__main__":
    main()