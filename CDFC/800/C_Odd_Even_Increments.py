"""
==========================================================
|  Archivo       : C_Odd_Even_Increments.py
|  Autor         : Russell
|  Fecha         : 2026-02-07 22:48
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
    n: int = int(sys.stdin.readline())
    arr: List[int] = list(map(int, sys.stdin.readline().split()))
    parityEven: int = arr[0] % 2
    parityOdd: int = arr[1] % 2
    ansParityEven = True
    ansParityOdd = True
    for i in range(0, n, 2):
        ansParityEven &= ((arr[i] % 2) == parityEven)
    for i in range(1,n,2):
        ansParityOdd &= ((arr[i]%2) == parityOdd)
    if(ansParityEven and ansParityOdd):
        print("YES")
    else:
        print("NO")

def main() -> None:
    # CASO MULTI-TEST
    t = int(sys.stdin.readline())
    for _ in range(t):
        solve()

    # CASO SINGLE-TEST
    # solve()

if __name__ == "__main__":
    main()