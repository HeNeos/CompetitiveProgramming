n = int(input())
n += 1
    
# 2 = 2
# 2 + 1 = 3
# 2 + 1/(1 + 1/2) = 8/3
# 2 + 1/(1 + 1/(2 + 1)) = 11/4
# 2 + 1/(1 + 1/(2 + 1/(1 + 1))) = 19/7

dp = [0]*40000
dp[0] = 1
dp[1] = 1
def solve(x):
    for i in range(2, x+1):
        if i%3 == 0 or i%3 == 2:
            dp[i] = dp[i-1] + dp[i-2]
        else:
            dp[i] = 2*dp[i-1]*(i-1)//3 + dp[i-2]
    return dp[x]
        
def sum_digits(n):
    s = 0
    while n:
        s += n % 10
        n //= 10
    return s

print(sum_digits(solve(n)))
# a(3n) = a(3n-1) + a(3n-2), a(3n+1) = 2n*a(3n) + a(3n-1), a(3n+2) = a(3n+1) + a(3n).