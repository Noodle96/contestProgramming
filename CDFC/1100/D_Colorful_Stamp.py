"""
==========================================================
|  Archivo       : D_Colorful_Stamp.py
|  Autor         : Russell
|  Fecha         : 2026-02-07 22:14
|--------------------------------------------------------
|  Tópicos utilizados:
|  - implementation
|  - training
|  - *1100
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
    # leemos una cadena
    
    str_w: str = sys.stdin.readline().rstrip('\n')
    arr: List[str] = []
    str_temp: str = ""
    for w in str_w:
        if(w == 'W'):
            if(str_temp != ""):
                arr.append(str_temp)
            str_temp = ""
        else:
            str_temp += w
    if str_temp != "":
        arr.append(str_temp)
    
    ans: str = "YES"
    for arr_i in arr:
        red: int = 0
        blue: int = 0
        for w in arr_i:
            if w == 'R':
                red += 1
            else:
                blue += 1
        if red <= 0 or blue <= 0 :
            ans = "NO"
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