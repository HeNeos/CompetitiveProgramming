dp = dict()

def all_sum_dig(cap, tot):
    if cap < 0 or tot < 0:
        return (0,0)
    if tot == 0:
        return (1,0)
    if cap == 0:
        return (0,0)

    if cap in dp and tot in dp[cap]:
        return dp[cap][tot]

    count = 0
    total = 0
    for k in range(min(10, tot + 1)):
        if k <= (cap%10):
            cnt, tt = all_sum_dig(cap//10, tot - k)
            count += cnt
            total += cnt * k + 10 * tt
        else:
            if cap < 10:
                continue
            cnt,tt = all_sum_dig(cap//10 - 1, tot - k)
            count += cnt
            total += cnt * k + 10 * tt

    if cap not in dp:
        dp[cap] = dict()
    dp[cap][tot] = (count, total)
    return count, total

def F(N):
    res = 0
    for tot in range(1, len(str(N)) * 9 + 1):
        res += all_sum_dig(N, tot)[1] / tot
    return res

print(F(1234567890123456789))
