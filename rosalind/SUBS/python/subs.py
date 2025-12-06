s = input()
t = input()

sz = len(s)
last_p = 0

while last_p < sz:
    new_p = s.find(t, last_p)
    if new_p == -1:
        break
    print(new_p + 1, end=" ")
    last_p = new_p + 1
