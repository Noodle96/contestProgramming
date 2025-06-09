import math

limit = 201

n = int(input())
numbers = map(int, input().split())

pows = {}

for i in range(0,limit+1):
    pows[i] = 0

for x in numbers:
    # exp = int(math.log2(x))
    exp = x.bit_length() - 1
    # if exp in pows:
    pows[exp] += 1


# # print('outpu: ')
# print(pows)

for i in range(0, limit):
    value = pows[i]
    pows[i+1] += (value // 2)
    pows[i] = value % 2

for i in range(limit, -1, -1):
    value = pows[i]
    if value != 0:
        print(2**i)
        break



