"""
==========================================================
|  Archivo       : E_Romantic_Glasses.py
|  Autor         : Russell
|  Fecha         : 2026-09-02 18:21
|--------------------------------------------------------
|  Tópicos utilizados:
|  - number theory
|  - training
|  - Lev 2
==========================================================
"""

from typing import List, Dict
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
    data = sys.stdin.readline().split()
    if not data:
        return
    n: int = int(data[0])
    arr: List[int] = list(map(int, sys.stdin.readline().split()))
    for i in range(n):
        if i & 1:
            arr[i] = -arr[i]
    
    prefix_sum: List[int] = [0] * (n + 1)
    existZero: bool = False
    for i in range(1, n + 1):
        prefix_sum[i] = prefix_sum[i - 1] + arr[i - 1]
        if prefix_sum[i] == 0:
            existZero = True
    #  ahora ordenamos de manera ascendente
    prefix_sum.sort(reverse=False)
    if existZero:
        print("YES")
        return
    ans: bool = False
    for i in range(0, n):
        ans |= (prefix_sum[i] == prefix_sum[i+1])
    print("YES" if ans else "NO")


def main() -> None:
    # CASO MULTI-TEST
    t = int(sys.stdin.readline())
    for _ in range(t):
        solve()

    # CASO SINGLE-TEST
    # solve()

if __name__ == "__main__":
    main()