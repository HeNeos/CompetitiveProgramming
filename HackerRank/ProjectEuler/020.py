import math
def sum_digits(n):
    s = 0
    while n:
        s += n % 10
        n //= 10
    return s
t = int(input())

for _ in range(t):
    n = int(input())
    ans = sum_digits(math.factorial(n))
    print(ans)
