grid: list[list[int]] = []
grid_length: int = 0

while True:
    try:
        line = input().strip()
    except Exception:
        break
    if "S" in line:
        grid_length = len(line)
        position = line.index("S")
        grid.append([position])
    elif "^" in line:
        characters = enumerate(line)
        positions: list[int] = [i for i, letter in characters if letter == "^"]
        grid.append(positions)

start_position: int = grid[0][0]
current_positions: set[int] = {start_position}
ans: int = 0

for line in grid[1:]:
    splitter_positions = set(line)
    common_positions = splitter_positions & current_positions
    new_positions: set[int] = {
        position for position in current_positions - splitter_positions
    }
    for position in common_positions:
        is_splitted: bool = False
        if position - 1 >= 0:
            new_positions.add(position - 1)
            is_splitted = True
        if position + 1 < grid_length:
            new_positions.add(position + 1)
            is_splitted = True
        ans += 1 if is_splitted else 0
    current_positions = new_positions


print(ans)
