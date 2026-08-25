"""
==========================================================
|  Archivo       : E_Binary_Deque.py
|  Autor         : Russell
|  Fecha         : 2026-08-24 18:36
|--------------------------------------------------------
|  Tópicos utilizados:
|  - binary search
|  - prefix_sum
|  - *1200
|  - training
==========================================================
"""

from typing import List
from bisect import bisect_left, bisect_right
import sys
INF: int = 10**9

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
    # data = sys.stdin.readline().split()
    # if not data:
    #     return
    # n: int = int(data[0])
    # arr: List[int] = list(map(int, sys.stdin.readline().split()))
    # print(n)
    # print(" ".join(map(str, arr)))

    data: List[str] = sys.stdin.readline().split()
    if not data:
        return
    n: int = int(data[0])
    s: int
    if(len(data) > 1):
        s = int(data[1])
    else:
        s = int(sys.stdin.readline().strip())

    # Leemos el array
    arr: List[int] = list(map(int, sys.stdin.readline().split()))
    suma: int = sum(arr)
    if(suma < s):
        print(-1)
        return
    if(suma == s):
        print(0)
        return

    deleted_ones: int = suma - s
    # Inicializacion de arrglos
    left_prefix_sum: List[int] = [0] * (n + 1)
    right_prefix_sum: List[int] = [0] * (n + 1)
    for i in range(1, n+1):
        left_prefix_sum[i] = left_prefix_sum[i-1] + arr[i - 1]
    arr.reverse()
    for i in range(1, n +1 ):
        right_prefix_sum[i] = right_prefix_sum[i - 1] + arr[i - 1]

    ans: int = INF
    for num_a in range(0, deleted_ones + 1):
        num_b: int = deleted_ones - num_a
        pos_a: int = bisect_left(left_prefix_sum, num_a)
        pos_b: int = bisect_left(right_prefix_sum, num_b)
        ans = min(ans, pos_a + pos_b)
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