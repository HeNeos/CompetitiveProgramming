inp = input().split()
n = int(inp[0])
k = int(inp[1])

rabbits = dict()

rabbits[0] = 1
for day in range(1, n):
    new_rabbits = 0
    for lived_days in range(k, 0, -1):
        rabbits[lived_days] = rabbits.get(lived_days-1, 0)
        if lived_days > 1:
            new_rabbits += rabbits[lived_days]
    rabbits[0] = new_rabbits;

print(rabbits)

ans = sum(rabbits.values()) - rabbits[k]
print(ans)
