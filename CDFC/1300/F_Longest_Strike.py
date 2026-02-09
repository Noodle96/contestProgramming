"""
==========================================================
|  Archivo       : F_Longest_Strike.py
|  Autor         : Russell
|  Fecha         : 2026-02-08 21:42
|--------------------------------------------------------
|  Tópicos utilizados:
|  - sorting
|  - training
|  - greedy
|  - data structures
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
    n: int
    k: int
    n, k = map(int, sys.stdin.readline().split())

    freq: Dict[int, int] = {}
    vec: List[int] = []

    arr: List[int] = list(map(int, sys.stdin.readline().split()))
    for a in arr:
        freq[a] = freq.get(a, 0) + 1
        vec.append(a)

    vec.sort()
    # eliminar duplicados (equivalente a unique)
    vec = list(dict.fromkeys(vec))

    n_: int = len(vec)
    i: int = 0

    l: int = -1
    r: int = -1
    current: int = -1

    def find_next_valid() -> None:
        nonlocal i, l, r, current
        # encontrar el siguiente valor con freq >= k
        while i < n_ and freq[vec[i]] < k:
            i += 1
        if i < n_:
            l = vec[i]
            r = vec[i]
            current = vec[i]
            i += 1

    max_ans: int = -1
    ans_l: int = -1
    ans_r: int = -1

    def add_segment(L: int, R: int) -> None:
        nonlocal max_ans, ans_l, ans_r
        if R - L > max_ans:
            max_ans = R - L
            ans_l = L
            ans_r = R

    while i < n_:
        find_next_valid()
        while i < n_:
            if freq[vec[i]] >= k:
                if vec[i] == current + 1:
                    r = vec[i]
                    current = vec[i]
                    i += 1
                else:
                    add_segment(l, r)
                    find_next_valid()
            else:
                add_segment(l, r)
                find_next_valid()

    if l != -1 and r != -1:
        add_segment(l, r)

    if max_ans == -1:
        print(-1)
    else:
        print(ans_l, ans_r)


def main() -> None:
    # CASO MULTI-TEST
    t: int = int(sys.stdin.readline())
    for _ in range(t):
        solve()

    # CASO SINGLE-TEST
    # solve()


if __name__ == "__main__":
    main()
