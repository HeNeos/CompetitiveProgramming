from functools import reduce
from operator import mul


def split_by_positions(s: str, positions: list[int]) -> list[str]:
    chunks: list[str] = []
    start = 0

    for pos in positions:
        chunks.append(s[start:pos])  # up to pos-1
        start = pos + 1  # skip the pos index

    chunks.append(s[start:])  # rest of the string
    return chunks


def get_numbers(column: list[str]) -> list[int]:
    lengths: list[int] = [len(number) for number in column]
    max_length: int = reduce(max, lengths)
    numbers: list[int] = []
    for position in range(max_length - 1, -1, -1):
        number = 0
        for value in column:
            if position < len(value) and value[position] != " ":
                digit = int(value[position])
                number *= 10
                number += digit
        numbers.append(number)

    return numbers


rows: list[str] = []
separator_positions: set[int] = set()
while True:
    try:
        line = input()
    except Exception:
        break
    if len(line) == 0:
        break
    # sanitized_line = " ".join(line.split())
    # values = sanitized_line.split(" ")
    rows.append(line)
    positions = {ind for ind, ch in enumerate(line) if ch.lower() == " "}
    if len(separator_positions) == 0:
        separator_positions = positions
    else:
        separator_positions &= positions

separators = sorted(separator_positions)

operators: list[str] = " ".join(rows[-1].split()).split(" ")
sanitized_rows: list[list[str]] = [
    split_by_positions(row, separators) for row in rows[:-1]
]

columns = [
    [sanitized_rows[i][j] for i in range(len(sanitized_rows))]
    for j in range(len(sanitized_rows[0]))
]

ans = 0
for operator, column in zip(operators, columns):
    sanitized_column = get_numbers(column)
    if operator == "*":
        ans += reduce(mul, sanitized_column)
    elif operator == "+":
        ans += sum(sanitized_column)

print(ans)
