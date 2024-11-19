from math import gcd
from time import time

# Tipo alias
from typing import Tuple

ll = int  # Usamos int ya que en Python no hay distinción con long long
ld = float
uint = int  # Python no tiene tipos sin signo explícitos
ull = int  # Igual que ll

pair2 = Tuple
pii = Tuple[int, int]
pli = Tuple[int, int]
pll = Tuple[int, int]

def combinations(n: ll, m: ll) -> ll:
    """Calcula combinaciones C(n, m)"""
    if m < n - m:
        m = n - m
    ans = 1
    for i in range(m + 1, n + 1):
        ans *= i
    for i in range(1, n - m + 1):
        ans //= i
    return ans

def solve():
    """Función principal para resolver el problema"""
    while True:
        try:
            n, m = map(int, input().split())
            if n != 0 or m != 0:
                if n == m:
                    print(f"{n} things taken {m} at a time is 1 exactly.")
                else:
                    ans = combinations(n, m)
                    print(f"{n} things taken {m} at a time is {ans} exactly.")
        except EOFError:
            break

if __name__ == "__main__":
    # Configuración inicial
    # import sys
    # input = sys.stdin.read
    solve()
