MOD = pow(10, 9) + 7
N = pow(10, 14)
N_2 = pow(10, 7)

a = [0] + [1]*(N_2)
for i in range(N_2, 0, -1):
    a[i] = N//(i*i)
    for j in range(2, N_2//i+1):
        a[i] -= a[i*j]

ans = 0
for i in range(0, len(a)):
    ans += (i*i*a[i])
    ans %= MOD

print(ans)
