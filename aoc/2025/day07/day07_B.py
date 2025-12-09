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
dp: dict[str, int] = {}
ans: int = 0


def explore_timelines(tachyion_position: int, position: int) -> int:
    if position >= len(grid):
        return 1

    encoded_state = f"{tachyion_position}#{position}"
    if encoded_state in dp:
        return dp[encoded_state]

    splitter_positions = grid[position]
    ans: int = 0
    if tachyion_position in splitter_positions:
        if tachyion_position - 1 >= 0:
            ans += explore_timelines(tachyion_position - 1, position + 1)
        if tachyion_position + 1 < grid_length:
            ans += explore_timelines(tachyion_position + 1, position + 1)
    else:
        ans += explore_timelines(tachyion_position, position + 1)
    dp[encoded_state] = ans
    return ans


ans = explore_timelines(start_position, 1)

print(ans)
