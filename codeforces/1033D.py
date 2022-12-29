n = int(input())

def solve(n, p):
    lo = 1
    hi = 2000000000
    while lo < hi:
        me = lo + (hi - lo + 1)//2
        if pow(me, p) <= n:
            lo = me
        else:
            hi = me-1
    return lo

m = {}
vals = []
primes = set()
for _ in range(n):
    x = int(input())
    found = False
    for exponents in [2, 3, 4]:
        xx = solve(x, exponents)
        if pow(xx, exponents) == x:
            primes.add(xx)
            m[xx] += exponents
            found = True
            break
    vals.append(x)

for val in vals:
    found = False
    for prime in primes:
        if val%prime == 0:
            found = True
            m[prime] += 1
            m[val//prime] += 1
            primes.add(val//prime)
            break
    if not found:
