import math

k, n = input().split()
k = int(k)
n = int(n)

for i in range(2**k):
    ans = 0
    for j in range(n):
        num = i + j * 2**k
        if num > n:
            break
        ans += math.comb(n, num)
        ans %= 998244353
    print(ans)


