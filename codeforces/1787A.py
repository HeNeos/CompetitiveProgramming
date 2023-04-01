t = int(input())

for _ in range(t):
    n = int(input())
    if n%2 == 0:
        print(1, n//2)
        continue
    found = False
    for x in range(3, n//3, 2):
        if pow(2, x)*x + pow(x, 2)*2 > n:
            break
        for y in range(2, n):
            ans = pow(y, x)*x + pow(x, y)*y
            if ans > n:
                break
            if ans == n:
                print(x, y)
                found = True
                break
        if found:
            break
    if not found:
        print(-1)