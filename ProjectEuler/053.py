import math
f = [0]*1005
f[0] = 1
for i in range(1, 1005):
    f[i] = f[i-1]*i

def comb(n, r):
    return f[n]/(f[r]*f[n-r])

n = 100
k = 1000000

ans = 0
for _n in range(1, n+1):
    aux = 0
    for r in range((_n-1)//2, -1, -1):
        if comb(_n, r) > k:
            aux += 2
        else:
            break
    ans += aux
    if _n%2 == 0:
        if comb(_n, _n//2) > k:
            ans += 1        
print(ans)