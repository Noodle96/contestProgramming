"""
==========================================================
|  Archivo       : F_Binary_String_Reconstruction.py
|  Autor         : Russell
|  Fecha         : 2026-02-07 16:54
|--------------------------------------------------------
|  Tópicos utilizados:
|  - constructive algorith
|  - *1500
|  - Training
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
    n1:int
    n2:int
    n3:int
    n1, n2, n3 = map(int, sys.stdin.readline().split())

    # Caso 1: solo ceros
    if n2 == 0 and n3 == 0:
        print('0' * (n1 + 1))
        return

    # Caso 2: solo alternancia (empieza en 1)
    if n1 == 0 and n3 == 0:
        ans: str = "10"
        for e in range(n2 - 1):
            ans += '1' if e % 2 == 0 else '0'
        print(ans)
        return

    # Caso 3: solo unos
    if n1 == 0 and n2 == 0:
        print("1" * (n3 + 1))
        return

    ans: str = ""

    # Bloque inicial de unos
    if n3 > 0:
        ans += "1" * (n3 + 1)
    else:
        ans += "1"

    if n2 & 1:
        # n2 impar
        for i in range(n2):
            ans += '0' if i % 2 == 0 else '1'
        ans += "0" * n1
    else:
        # n2 par
        for i in range(n2 - 1):
            ans += '0' if i % 2 == 0 else '1'
        ans += "0" * n1
        ans += "1"

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