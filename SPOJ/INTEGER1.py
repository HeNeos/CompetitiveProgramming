from math import *

def find_lower(x, y):
    lo = 1
    hi = x
    while lo < hi:
        me = lo + (hi - lo + 1)//2
        if me**y <= x:
            lo = me
        else:
            hi = me-1
    return lo

def find_upper(x, y):
    lo = 1
    hi = x
    while lo < hi:
        me = lo + (hi - lo)//2
        if me**y < x:
            lo = me+1
        else:
            hi = me
    return lo

def get_divisors(x):
    count = 0
    # ans = []
    for i in range(1, x+1):
        if i*i > x:
            break
        if x%i == 0:
            count += i
            # ans.append(i)
            if x//i != i:
                count += x//i
                # ans.append(x//i)
    return count-x

while True:
    a, b = input().split()
    a = int(a)
    b = int(b)
    if a == 0 and b == 0:
        break
    ans = 0
    for i in range(64, 0, -1):
        r = find_lower(b, i)
        l = find_upper(a, i)
        ans += i*(r-l+1)
        ans -= get_divisors(i)*(r-l+1)
        # print(i, l, r)
    print(ans)