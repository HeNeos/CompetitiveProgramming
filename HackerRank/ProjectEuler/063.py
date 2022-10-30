def count_digits(n):
    ans = 0
    while n > 0:
        n //= 10
        ans += 1
    return ans

n = int(input())

ind = 1
value = 1**n
while count_digits(value) <= n:
    if count_digits(value) == n:
        print(value)
    ind += 1
    value = ind**n