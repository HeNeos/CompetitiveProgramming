from dataclasses import dataclass

@dataclass
class Point:
    x: int = 0
    y: int = 0

@dataclass
class Segment:
    start: Point
    end: Point

def find_intersection(l: Segment) -> float:
    delta_y = l.start.y - l.end.y
    if delta_y == 0:
        return -1
    k = l.start.y / delta_y
    if l.end.y*l.start.y > 0:
        return -1
    t = l.start.x + k * (l.end.x - l.start.x)
    return t

def solve(triangle: list[Segment]):
    values = set()
    for side in triangle:
        t = find_intersection(side)
        if t >= 0:
            values.add(t)
    if 0 in values:
        return 1
    else:
        return len(values) % 2

with open("triangles.txt") as f:
    lines = f.readlines()
    ans = 0
    for line in lines:
        points = line.split(',')
        A = Point(int(points[0]), int(points[1]))
        B = Point(int(points[2]), int(points[3]))
        C = Point(int(points[4]), int(points[5]))
        first_side = Segment(A, B)
        second_side = Segment(B, C)
        third_side = Segment(A, C)
        ans += solve([first_side, second_side, third_side])

    print(ans)