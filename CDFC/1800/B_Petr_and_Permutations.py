"""
==========================================================
|  Archivo       : B_Petr_and_Permutations.py
|  Autor         : Russell
|  Fecha         : 2026-09-07 16:32
|--------------------------------------------------------
|  Tópicos utilizados:
|  - number theory
|  - training
|  - Lev 2
==========================================================
"""

from typing import List, Set, Tuple, Iterator, Dict, Any, Optional, Generator
import sys

# Generador global que leerá toda la entrada de forma eficiente
def token_generator() -> Generator[str, None, None]:
    for line in sys.stdin:
        for token in line.split():
            yield token

# Instanciamos el iterador global
tokens = token_generator()

def next_token() -> str:
    return next(tokens)


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

class Fenwick:
    def __init__(self, n: int) -> None:
        self.n: int = n
        self.bit: List[int] = [0]* (n + 1)
    def update(self, idx: int, val: int) -> None:
        while idx <= self.n:
            self.bit[idx] += val
            idx += (idx & -idx)
    def query(self, idx: int) -> int:
        sum: int = 0
        while idx > 0:
            sum += self.bit[idx]
            idx -= (idx & -idx)
        return sum
    def query_range(self, l: int, r: int) -> int:
        return self.query(r) - self.query(l - 1)

def solve() -> None:
    n: int = int(next_token())
    arr: List[int] = [int(next_token()) for _ in range(n)]
    ft: Fenwick = Fenwick(n)
    inversions: int = 0
    for i in range(n -  1, -1, -1):
        inversions += ft.query(arr[i] - 1)
        ft.update(arr[i], +1)

    status: bool = (inversions % 2)
    if (3 * n)  % 2 == status:
        print("Petr")
    else:
        print("Um_nik")


def main() -> None:
    # CASO MULTI-TEST
    # t = int(sys.stdin.readline())
    # for _ in range(t):
    #     solve()

    # CASO SINGLE-TEST
    solve()

if __name__ == "__main__":
    main()