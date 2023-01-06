t = int(input())

for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    s = sum(arr)
    a = arr.copy()
    b = arr.copy()
    
    for i in range(n):
        if i%2 == 0:
            a[i] = 1
        else:
            b[i] = 1

    if 2*sum(list(map(lambda x, y: abs(x-y), arr, a))) <= s:
        print(*a)
    else:
        print(*b)