def convert_base_b_to_base_10(num: str, base: int) -> int:
    return int(num, base)

def convert_base_10_to_base_n(num: int, base: int) -> str:
    if num == 0:
        return "0"
    
    digits = []
    while num:
        remainder = num % base
        if remainder < 10:
            digits.append(chr(ord('0') + remainder))
        else:
            digits.append(chr(ord('A') + (remainder - 10)))
        num //= base
    digits.reverse()
    return ''.join(digits)

def modB(base10, B):
    return base10 % B

while True:
    numbers = input().split()
    base = int(numbers[0])
    if base == 0:
        break
    else:
        p, m = str(numbers[1]), str(numbers[2])
        p  = convert_base_b_to_base_10(p, base)
        m = convert_base_b_to_base_10(m, base)
        ans = modB(p, m)
        ans = convert_base_10_to_base_n(ans, base)
        print(ans)