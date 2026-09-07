"""
==========================================================
|  Archivo       : F_Greetings.py
|  Autor         : Russell
|  Fecha         : 2026-09-07 10:12
|--------------------------------------------------------
|  Tópicos utilizados:
|  - number theory
|  - training
|  - Lev 2
==========================================================
"""

from typing import List, Tuple, Set, Iterator, Dict, Any, Optional, Generator
import sys
from bisect import bisect_left, bisect_right

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
        self.bit: List[int] = [0] * (n + 1)

    def update(self, idx: int, val: int) -> None:
        while idx <= self.n:
            self.bit[idx] += val
            idx += idx & -idx

    def query_single(self, idx: int) -> int:
        total_sum: int = 0
        while idx > 0:
            total_sum += self.bit[idx]
            idx -= idx & -idx
        return total_sum

    def query(self, l: int, r: int) -> int:
        return self.query_single(r) - self.query_single(l - 1)

def solve() -> None:
    n: int = int(next_token())
    a: List[Tuple[int, int]] = []
    for i in range(n):
        x: int = int(next_token())
        y: int = int(next_token())
        a.append((x,y))
    # print("print a")
    # print(*a)

    # Ordenamos por el priemr elemento a[i].first
    a.sort(key=lambda x: x[0])

    vals: List[int] = sorted(list(set(y for x,y in a)))
    def get_id(x: int) -> int:
        return bisect_left(vals, x) + 1
    
    ft: Fenwick = Fenwick(len(vals))
    ans: int = 0
    for i in range(n - 1, -1, -1):
        id: int = get_id(a[i][1])
        ans += ft.query_single(id)
        ft.update(id, +1)
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