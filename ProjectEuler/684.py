f = [(0, 0), (0, 1)]

def fill():
    for i in range(2, 90+1):
        a = f[i-1]
        b = f[i-2]
        d = a[0] + b[0]
        r = a[1] + b[1]
        if r >= 9:
            d += 1
            r -= 9
        f.append((d, r))

def g(fib):
    d = fib[0]
    r = fib[1]
    m = 10**9 + 7
    pow_mod = pow(10, d%(m-1), m)
    return ( (r+1) * pow_mod - 1 )%m


# g(n) = (n%9 + 1)*(10^(n//9)) - 1
# sum g(i) = r*(10^(n+1)-1)/9 - (n+1)
# sum sum g(i) = 5*(10^(n+1)-1) - 9*(n+1)

def S(fib):
    n = fib[0]
    r = fib[1] + 2
    return (((r-1)*r + 10)*pow(10, n, 10**9+7) - 2*(r+9*n+4)) * 500000004

fill()
ans = 0
for i in range(2, len(f)):
    print(i, f[i])
    ans += S(f[i])%(10**9+7)
print(ans%(10**9+7))
