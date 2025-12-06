text: str = input()
reversed_text: str = text[::-1]

letters: str = "ACGT"
chars_to_index: dict[str, int] = {letter: index for index, letter in enumerate(letters)}

reverse_complement: str = "".join(
    [letters[3 - chars_to_index[char]] for char in reversed_text if char in letters]
)
print(reverse_complement)
