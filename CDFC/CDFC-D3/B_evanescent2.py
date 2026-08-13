"""
==========================================================
|  Archivo       : B_Evanescent2.py
|  Autor         : Russell
|  Fecha         : 2026-08-12 18:08
|--------------------------------------------------------
|  Tópicos utilizados:
|  - strings
|  - greedy
|  - implementation
==========================================================
"""

from typing import List, Set
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


def compress(chars: List[str]) -> int:
    """Longitud tras comprimir corridas consecutivas iguales"""
    res: List[str] = []
    c: str
    for c in chars:
        if not res or res[-1] != c:
            res.append(c)
    return len(res)


def solve() -> None:
    n: int = int(sys.stdin.readline())
    s: List[str] = list(sys.stdin.readline().strip())

    index_delete: int = -1
    set1: Set[int] = set()
    set2: Set[int] = set()
    set3: Set[int] = set()
    set4: Set[int] = set()

    i: int
    for i in range(1, n - 1):
        if s[i - 1] == s[i + 1] and s[i] != s[i + 1]:
            set1.add(i)
        if s[i - 1] != s[i] and s[i] != s[i + 1]:
            set2.add(i)
        if (s[i - 1] == s[i] and s[i] != s[i + 1]) or (s[i] == s[i + 1] and s[i] != s[i - 1]):
            set3.add(i)
        if s[i - 1] == s[i] and s[i] == s[i + 1]:
            set4.add(i)

    if set1:
        index_delete = min(set1)
    elif set2:
        index_delete = min(set2)
    elif set3:
        index_delete = min(set3)
    elif set4:
        index_delete = min(set4)

    del s[index_delete]

    print(compress(s))


def main() -> None:
    # CASO MULTI-TEST
    t: int = int(sys.stdin.readline())
    _: int
    for _ in range(t):
        solve()

    # CASO SINGLE-TEST
    # solve()

if __name__ == "__main__":
    main()