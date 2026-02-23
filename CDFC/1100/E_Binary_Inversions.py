"""
==========================================================
|  Archivo       : E_Binary_Inversions.py
|  Autor         : Russell
|  Fecha         : 2026-02-14 17:20
|--------------------------------------------------------
|  Tópicos utilizados:
|  - prefix sum
|  - training
|  - *1100
==========================================================
"""

from typing import List
import sys


def gcd(a: int, b: int) -> int:
    if a % b == 0:
        return b
    return gcd(b, a % b)


def floordiv(a: int, b: int) -> int:
    if a >= 0:
        return a // b
    return -((-a + b - 1) // b)


def ceildiv(a: int, b: int) -> int:
    if a >= 0:
        return (a + b - 1) // b
    return -((-a) // b)


def bitlen_unsigned(n: int) -> int:
    return 1 if n == 0 else n.bit_length()


def solve() -> None:
    n: int = int(sys.stdin.readline())
    a: List[int] = list(map(int, sys.stdin.readline().split()))
    b: List[int] = a.copy()

    ans: int = 0

    def compute(base: List[int]) -> int:
        ps: List[int] = [0] * n
        ps[n - 1] = 1 if base[n - 1] == 0 else 0
        for i in range(n - 2, -1, -1):
            ps[i] = ps[i + 1] + (1 if base[i] == 0 else 0)

        inv: int = 0
        for i in range(n):
            if base[i] == 1:
                inv += ps[i]
        return inv

    # Caso 1: original
    ans = max(ans, compute(a))

    # Caso 2: cambiar primer 0 → 1
    a2: List[int] = a.copy()
    for i in range(n):
        if a2[i] == 0:
            a2[i] = 1
            break
    ans = max(ans, compute(a2))

    # Caso 3: cambiar último 1 → 0
    b2: List[int] = b.copy()
    for i in range(n - 1, -1, -1):
        if b2[i] == 1:
            b2[i] = 0
            break
    ans = max(ans, compute(b2))

    print(ans)


def main() -> None:
    t: int = int(sys.stdin.readline())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
