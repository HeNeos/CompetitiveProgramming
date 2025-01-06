N = 60

f = [0]*N
def fill():
  f[0] = 0
  for i in range(1, N):
    f[i] = f[i-1] + i*(1<<(i-1))

def find_sum(first_m, level):
  if level == 1:
    return first_m-1
  amount_level = first_m//2
  return find_sum(first_m - amount_level, level-1) + amount_level * level

def solve(n):
  total_sum = 0
  for i in range(1, N):
    if n == 0:
      break
    length = (1<<i)
    if n >= length:
      total_sum += f[i]
      n -= length
    else:
      total_sum += find_sum(n, i)
      break

  return total_sum


fill()
ans = solve(10**16)
print(ans)