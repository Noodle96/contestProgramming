"""
==========================================================
|  Archivo       : E_Special_Elements.py
|  Autor         : Russell
|  Fecha         : 2026-02-07 17:23
|--------------------------------------------------------
|  Tópicos utilizados:
|  - number theory
|  - training
|  - Lev 2
==========================================================
"""

from typing import List,Dict
from collections import defaultdict
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
    a: List[int] = list(map(int, sys.stdin.readline().split()))

    prefix_sum: Dict[int, bool] = {}

    for i in range(n - 1):
        s: int = a[i]
        for j in range(i + 1, n):
            s += a[j]
            if s >= n + 1:
                break
            prefix_sum[s] = True

    ans: int = 0
    for ai in a:
        if ai in prefix_sum:
            ans += 1

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