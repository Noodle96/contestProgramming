import collections
n = int(input())
a = list(map(int, input().split()))

freq = collections.Counter(x.bit_length() - 1 for x in a)

for i in range(200):  # margen seguro
    carry = freq[i] // 2
    freq[i] %= 2
    freq[i + 1] += carry

# resultado = 2^max_exponente que quedó con freq[x] == 1
for i in reversed(range(200)):
    if freq[i]:
        print(2 ** i)
        break