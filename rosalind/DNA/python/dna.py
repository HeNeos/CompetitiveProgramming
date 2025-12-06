text = input()

characters = ["A", "C", "G", "T"]
ans = [len([1 for c in text if c == character]) for character in characters]
print(*ans)
