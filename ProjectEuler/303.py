small_numbers = []
cache = dict()
def fill():
  small_numbers.append([1, 2])
  for i in range(1, 16):
    small_numbers.append([])
    for j in range(len(small_numbers[i-1])):
      current_number = small_numbers[i-1][j]
      for d in range(3):
        small_numbers[i].append(current_number*10 + d)

  initial = 9
  for i in range(1, 5):
    value = (pow(10, i) - 1)//9
    value *= pow(10, 4*i)
    value += (pow(10, 4*i) - 1)//9 * 2
    cache[initial] = value
    initial *= 10
    initial += 9
  
def solve(n):
  if n in cache:
    return cache[n]//n
  for i in range(len(small_numbers)):
    for v in small_numbers[i]:
      if v%n == 0:
        return v//n

fill()

ans = 0
for i in range(1, 10000+1):
  value = solve(i)
  if value is None:
    print(i)
    continue
  ans += solve(i)

print(ans)