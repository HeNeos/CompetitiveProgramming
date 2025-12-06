from functools import reduce
from operator import mul

rows: list[list[str]] = []
while True:
    try:
        line = input().strip()
    except Exception:
        break
    if len(line) == 0:
        break
    sanitized_line = " ".join(line.split())
    values = sanitized_line.split(" ")
    rows.append(values)

operators: list[str] = rows[-1]
columns = [[int(rows[i][j]) for i in range(len(rows) - 1)] for j in range(len(rows[0]))]

ans = 0
for operator, column in zip(operators, columns):
    if operator == "*":
        ans += reduce(mul, column)
    elif operator == "+":
        ans += sum(column)

print(ans)
