# n = 2000000
n = 20000
MOD = 50515093

s = [[0, 0] for i in range(n)]

def fill():
    s[0][0] = 290797
    s[0][1] = (s[0][0]*s[0][0])%MOD
    for i in range(1, n):
        s[i][0] = s[i-1][1]**2
        s[i][0] %= MOD
        s[i][1] = s[i][0]**2
        s[i][1] %= MOD

def dist(a, b):
    return (a[0]-b[0])**2 + (a[1]-b[1])**2

def solve(points):
    m = len(points)
    if m == 2:
        return dist(points[0], points[1])
    if m == 3:
        return min(
            dist(points[0], points[1]), 
            dist(points[1], points[2]), 
            dist(points[0], points[2])
        )
    
    mid = m//2
    dl = solve(points[:mid])
    dr = solve(points[mid:])
    d = min(dl, dr)

    strip = []
    for i in range(m):
        if abs(points[i][0] - points[m//2][0]) < d:
            strip.append(points[i])

    strip = sorted(strip, key=lambda point: point[1])

    for i in range(len(strip)):
        for j in range(i+1, len(strip)):
            if strip[j][1] - strip[i][1] >= d:
                break
            d = min(d, dist(strip[i], strip[j]))
    return d

fill()
s.sort()
ans = solve(s)

print(ans**0.5, ans)