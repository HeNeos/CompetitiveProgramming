from itertools import combinations
from functools import reduce

def t(x):
    return x * (x+1) * (x+2) // 6

def count_multiples(primes, n, k):
    total_count = 0
    num_primes = len(primes)
    
    for i in range(k, num_primes + 1):
        sign = (-1) ** (i - k)
        if i >= 14:
            break
        for combo in combinations(primes, i):
            product = reduce(lambda x,y: x*y, combo)
            if product > n:
                if combo[0] >= 5 and i >= 13:
                    break
                if combo[0] >= 7 and i >= 12:
                    break
                if combo[0] >= 13 and i >= 11:
                    break
                if combo[0] >= 23 and i >= 10:
                    break
                if combo[0] >= 43 and i >= 9:
                    break
                continue
            total_count += sign * (n // product) * t(i-k+1)
    return total_count

primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]
n = 10**16

result = count_multiples(primes, n, 4)
print(result)
