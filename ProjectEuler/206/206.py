n = 1388626530
change = True
while True:
    if change:
        n += 40
        change = False
    else:
        n += 60
        change = True
    s = str(n*n)
    if s[::2] == "1234567890":
        print(n, s)
        break