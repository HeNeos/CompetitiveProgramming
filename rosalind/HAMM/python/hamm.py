s = input()
t = input()

sz = len(s)

distance = 0
for i in range(sz):
    if s[i] != t[i]:
        distance += 1
print(distance)
