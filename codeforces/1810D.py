def calc_h(a, b, n):
    if n == 1:
        return 1, a
    previous = (n-2)*(a-b) + a + 1
    current = (n-1)*(a-b) + a
    return previous, current

def calc_days(h, a, b):
    # (x-1)*(a-b) + a >= h
    # x-1 + 1 + b/(a-b) >= h/(a-b)
    # x >= (h-b)/(a-b)
    ans = (h-b)//(a-b)
    if ans*a - (ans-1)*b >= h:
        return max(ans, 1)
    else:
        ans += 1
        if ans*a - (ans-1)*b >= h:
            return max(ans, 1)
        else:
            return max(ans+1, 1)

t = int(input())

for _ in range(t):
    q = int(input())
    low = -1
    high = -1
    for query in range(q):
        l = input().split()
        a = int(l[1])
        b = int(l[2])    
        if l[0] == "1":
            n = int(l[3])
            c_low, c_high = calc_h(a, b, n)
            if low == -1 and high == -1:
                low = c_low
                high = c_high
                print("1", end=" ")
            else:
                if c_high < low or c_low > high:
                    print("0", end=" ")
                else:
                    print("1", end=" ")
                    if c_low >= low and c_high <= high:
                        low = c_low
                        high = c_high
                        continue
                    if c_high <= high and c_low <= low:
                        high = c_high
                        continue
                    if c_low >= low and c_high >= high:
                        low = c_low
                        continue
        else:
            if low == -1 and high == -1:
                print("-1", end=" ")
                continue
            low_days = calc_days(low, a, b)
            high_days = calc_days(high, a, b)
            if low_days != high_days:
                print("-1", end=" ")
            else:
                print(low_days, end=" ")
    print()