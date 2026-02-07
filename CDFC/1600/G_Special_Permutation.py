"""
==========================================================
|  Archivo       : G_Special_Permutation.py
|  Autor         : Russell
|  Fecha         : 2026-02-07 16:08
|--------------------------------------------------------
|  Tópicos utilizados:
|  - constructive algorithm
|  - training
|  - *1600
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
    n: int = int(sys.stdin.readline())

    if n <= 3:
        print(-1)
        return

    if n == 4:
        print("3 1 4 2")
        return

    ans: List[int] = []

    if n % 2 == 0:
        # pares
        for i in range(1, n + 1, 2):
            ans.append(i)

        ans.append(n - 4)

        for i in range(n, 0, -2):
            if i != n - 4:
                ans.append(i)
    else:
        # impares
        for i in range(1, n + 1, 2):
            ans.append(i)

        ans.append(n - 3)

        for i in range(n - 1, 0, -2):
            if i != n - 3:
                ans.append(i)

    print(" ".join(map(str, ans)))


def main() -> None:
    # CASO MULTI-TEST
    t: int = int(sys.stdin.readline())
    for _ in range(t):
        solve()

    # CASO SINGLE-TEST
    # solve()


if __name__ == "__main__":
    main()
