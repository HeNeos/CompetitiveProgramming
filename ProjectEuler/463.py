from numbers import Integral

f_cache = {}
h_cache = {}
solve_cache = {}

def f(n: Integral) -> Integral:
    if n<= 1 or n == 3:
        return n
    if n in f_cache:
        return f_cache[n]
    if n%2 == 0:
        f_cache[n] = f(n//2)
        return f_cache[n]
    if n%4 == 1:
        f_cache[n] = 2*f((n+1)//2) - f((n-1)//4)
        return f_cache[n]
    if n%4 == 3:
        f_cache[n] = 3*f((n-1)//2) - 2*f((n+1)//4 - 1)
        return f_cache[n]

def h(n: Integral) -> Integral:
    if n == 0:
        return 1
    if n == 1:
        return 4
    if n in h_cache:
        return h_cache[n]
    if n%2 == 0:
        h_cache[n] = f(2*n+1) + h(n-1)
        return h_cache[n]
    p = (n-1)//2
    ans = -3*solve(p)
    ans += 5*h(p)
    ans -= 1
    h_cache[n] = ans
    return ans

def solve(n: Integral) -> Integral:
    if n <= 2:
        return n
    if n == 3:
        return 5
    if n in solve_cache:
        return solve_cache[n]
    if n%4 != 3:
        solve_cache[n] = f(n) + solve(n-1)
        return solve_cache[n]
    p = (n-3)//4
    ans = -2*solve(p)
    ans += 6*h(p)
    ans -= 1
    solve_cache[n] = ans
    return ans

n = 3**37
print(solve(n))
