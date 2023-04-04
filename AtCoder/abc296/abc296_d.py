n, m = input().split()
n = int(n)
m = int(m)

if n*n < m:
    print(-1)
else:
    a = (m+n-1)//n
    b = (m+a-1)//a
    ans = a*b

    for i in range(a+1, 2*a+1):
        new_a = i
        if new_a > n:
            break
        new_b = (m+new_a-1)//new_a
        if new_b < new_a:
            break
        ans = min(ans, new_a*new_b)
    print(ans)
