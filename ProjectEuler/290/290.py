f = {}
def dp(length, adv, diff):
    if length == 0:
        while adv != 0:
            diff += adv % 10
            adv = adv // 10
        return int(diff == 0)
    state = (length, adv, diff)
    if state in f:
        return f[state]
    ret = 0
    for i in range(10):
        prod = adv + i * 137
        ret += dp(length - 1, prod // 10, diff + prod % 10 - i)
    f[state] = ret
    return ret

print(dp(18, 0, 0))
