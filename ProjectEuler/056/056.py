def dig_sum(n):
    ans = 0
    while n > 0:
        ans += n%10
        n //= 10
    return ans

n = 100

max_sum = 0
for a in range(2, n):
    for b in range(1, n):
        max_sum = max(max_sum, dig_sum(a**b))
        
print(max_sum)
