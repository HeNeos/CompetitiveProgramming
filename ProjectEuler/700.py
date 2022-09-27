# an = b mod (m)
a = 1504170715041707
m = 4503599627370517
inverse_a = 3451657199285664

maxi = 0
mini = m

coins = []

for i in range(1, 50000000):
    if (i*a) % m < mini:
        mini = (i*a) % m
        coins.append((i, mini))

possible_coins = []

for i in range(1, mini):
    n = (inverse_a * i) % m
    possible_coins.append((n, i))

possible_coins.sort()

for i in range(len(possible_coins)):
    n = possible_coins[i][0]
    b = possible_coins[i][1]
    if b < mini:
        mini = b
        coins.append(possible_coins[i])

print(coins)