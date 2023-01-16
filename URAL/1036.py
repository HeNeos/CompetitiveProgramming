n, s = input().split()
n = int(n)
s = int(s)

if s%2 == 1 or s > 9*2*n:
    print(0)
else:
    s //= 2
    dp = [[0]*455 for _ in range(n+2)]
    dp[0][0] = 1
    for pos in range(1, n+1):
        for value in range(9*n+1):
            if dp[pos-1][value] != 0:
                for d in range(10):
                    dp[pos][value+d] += dp[pos-1][value]

    print(dp[n][s]*dp[n][s])