"""
==========================================================
|  Archivo       : B_Same_Parity_Summands.py
|  Autor         : Russell
|  Fecha         : 2026-02-07 18:12
|--------------------------------------------------------
|  Tópicos utilizados:
|  - math
|  - training
|  - constructive algorithms
|  - *1200
================================================
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
    if n % 2 == 0:
        # Podemos expresar n(PAR) como la suma de k(par-impar) pares
        p:int = n - 2 * k + 2
        if p > 1:
            print("YES")
            # imprimimos k - 1 veces el 2 y 1 vez el número p
            print(" ".join(["2"] * (k - 1) + [str(p)]))
        else:
            # veremos si es que podemos expresar n(PAR) como la suma de k(PAR) impares
            if k & 1:
                print("NO")
            else:
                p = n + 1 - k
                if p > 0:
                    print("YES")
                    # imprimimos k - 1 veces el 1 y 1 vez el número p
                    print(" ".join(["1"] * (k - 1) + [str(p)]))
                else:
                    print("NO")
    else:
        # verificamos si podemos expresar n(impar) como la suma de k(impar) impares
        if (k % 2 == 0):
            print("NO")
        else:
            p = n + 1 - k
            if(p > 0):
                print("YES")
                # imprimo k - 1 unosy una vez p
                print(" ".join(["1"]* (k-1) +  [str(p)]))
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