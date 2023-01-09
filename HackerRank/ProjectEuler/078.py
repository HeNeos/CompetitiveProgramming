MOD = 1000000007
N = 70005
dp = [0]*N

def fill():
    dp[0] = 1
    dp[1] = 1
    for i in range(2, N):
        dp[i] = 0
        j = 1
        while True:       
            pentagon = (3*j*j - j)//2
            if pentagon > i:
                break
            if abs(j-1)%2 == 0:
                dp[i] += dp[i-pentagon]
            else:
                dp[i] -= dp[i-pentagon]
            if j > 0:
                j = -j
            else:
                j = 1-j
                
t = int(input())
fill()
for _ in range(t):
    n = int(input())
    print(dp[n]%MOD)
