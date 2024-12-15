from math import *
import numpy as np
N = 100000


def solve_quadratic(a, b, c):
    if b*b - 4*a*c < 0:
        return None
    return np.array(
        [(-b + (sqrt(b*b - 4*a*c)))/(2*a), (-b - (sqrt(b*b - 4*a*c)))/(2*a)]
    )

def is_integer(x):
    if x - floor(x) < 0.00000000001:
        return True

def calc_dist(p1, p2):
    if p1 == p2:
        return None
    return sqrt((p1[0] - p2[0])**2 + (p1[1] - p2[1])**2)

count = 0
ans = 0
min_x = N
min_y = N
max_x = -N
max_y = -N
s = set()

for x_a in range(-3*N//16, 3*N//16+1):
    if x_a%500 == 0:
        print(x_a)
    for y_a in range(-3*N//16, 3*N//16+1):
        R_2 = x_a*x_a + y_a*y_a
        # x_b = 5-x_c-x_a
        # y_b = -y_c-y_a
        # x_b^2 + y_b^2 = R^2
        # x_c^2 + y_c^2 = R^2
        k_c = (2*x_a-10)
        if k_c == 0:
            continue
        l_c = 2*y_a
        m_c = y_a*y_a + x_a*x_a +  25 - 10*x_a
        # x_c = (-m_c - y_c*l_c)/k_c
        y_c = solve_quadratic(l_c*l_c + k_c*k_c, 2*m_c*l_c, m_c*m_c-R_2*k_c*k_c)
        if y_c is None:
            continue
        x_c = (-m_c - y_c*l_c)/k_c
        x_b = 5-x_c-x_a
        y_b = -y_c-y_a

        for i in range(2):
            if is_integer(x_c[i]) and is_integer(y_c[i]):
                a = calc_dist([int(x_b[i]), int(y_b[i])], [int(x_c[i]), int(y_c[i])])
                b = calc_dist([int(x_c[i]), int(y_c[i])], [x_a, y_a])
                c = calc_dist([int(x_b[i]), int(y_b[i])], [x_a, y_a])

                if a is None or b is None or c is None:
                    continue

                if a + b + c <= N:
                    solution = [[x_a, y_a], [int(x_b[i]), int(y_b[i])], [int(x_c[i]), int(y_c[i])]]
                    solution.sort()

                    if str(solution) not in s:
                        s.add(str(solution))
                        count += 1
                        ans += a+b+c
                        min_x = min(min_x, solution[0][0])
                        max_x = max(max_x, solution[2][0])
                        min_y = min(min_y, solution[0][1], solution[1][1], solution[2][1])
                        max_y = max(max_y, solution[0][1], solution[1][1], solution[2][1])
                        # print(solution)

print(count)
print(ans)
print([min_x, min_y], [max_x, max_y])