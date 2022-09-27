import math

x, y = 0.0, 10.1
nx, ny = 1.4, -9.6

#m = -4x/y
#4x^2+y^2=100

def solve(p1, p2, v):
    # 4(p1+t*v1)^2 + (p2+t*v2)^2 = 100
    # t^2*(4*v1^2 + v2^2) + t*(8*p1*v1 + 2*p2*v2) - 100 + p1^2 + p2^2 = 0
    x0 = v[0]
    y0 = v[1]
    b = 8*p1*x0 + 2*p2*y0
    a = 4*x0*x0 + y0*y0
    c = -100 + p2*p2 + 4*p1*p1
    ans1 = -b + math.sqrt(b*b-4*a*c)
    ans2 = -b - math.sqrt(b*b-4*a*c)
    ans1 /= (2*a)
    ans2 /= (2*a)
    if abs(ans1) > abs(ans2):
        return ans1
    else:
        return ans2

ans = 0
for _ in range(500):
    if abs(nx) <= 0.01 and ny > 0:
        break
    v1 = [nx - x, ny - y]
    m = -4*nx/ny
    v2 = [-1, -m]
    p = v1[0]*v2[0] + v1[1]*v2[1]
    theta = math.atan(m)
    alpha = p/(math.sqrt((nx-x)**2 + (ny-y)**2)*math.sqrt(m*m+1))
    
    alpha = math.acos(alpha)
    if alpha > math.pi/2:
        alpha = math.pi - alpha
    
    
    v1 = [-math.cos(alpha - theta), math.sin(alpha - theta)]
    x, y = nx, ny
    t = solve(x, y, v1)
    
    nx, ny = x + v1[0]*t, y + v1[1]*t
    
    print(_, nx, ny)
    ans += 1
    # x + v1*t, y + v1*t 
    # 4*(x2 + x0^2t^2 + 2x*x0t) + y2 + y0*t^2 + 2y*y0*t = 100
    # t^2(4*x0^2 + y0^2) + t(8*x*x0 + 2*y*y0) + y^2 + 4x^2 = 100
    # t =
    # a dot b = ab cos(alpha)
print(ans)