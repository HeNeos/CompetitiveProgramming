MOD = 1000000007

fact = [1]*1000005
for i in range(2, 1000005):
    fact[i] = (i*fact[i-1])%MOD

t = int(input())

for _ in range(t):
    n = int(input())
    ans = 1
    k = list(map(lambda x: int(x), input().split()))
    acum = 0
    for element in k:
        ans *= fact[acum+element-1]
        ans *= pow(fact[acum], MOD-2, MOD)
        ans *= pow(fact[element-1]%MOD, MOD-2, MOD)
        ans %= MOD
        acum += element
    print(f"Case {_+1}: {ans}")