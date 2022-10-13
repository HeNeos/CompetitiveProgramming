n = int(input())
ans = 0
for _ in range(1, n+1):
    ans += pow(_, _, 10**10)
    ans %= (10**10)
print(ans)
