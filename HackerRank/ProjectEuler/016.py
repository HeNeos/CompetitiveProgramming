def getSum(n):
    sum = 0
    while (n != 0):       
        sum = sum + (n % 10)
        n = n//10
    return sum

t = int(input())

for _ in range(t):
    n = int(input())
    v = 2**n
    print(getSum(v))
