from dataclasses import dataclass


content: str = ""
label: str = ""

data: dict[str, str] = dict()

while True:
    try:
        line = input().strip()
    except Exception:
        data[label] = content
        break

    if line.startswith(">"):
        if len(content) > 0 and len(label) > 0:
            content = content.replace("\n", "").strip()
            data[label] = content
        label = line.split(">", 1)[-1]
        content = ""
    else:
        content += line


@dataclass
class Fraction:
    numerator: int
    denominator: int


def process_content(content: str) -> Fraction:
    value: int = content.count("G") + content.count("C")
    return Fraction(numerator=value, denominator=len(content))


gc_content: dict[str, Fraction] = {
    label: process_content(content) for label, content in data.items()
}


best_label: str = ""
best_content: Fraction = Fraction(numerator=0, denominator=0)
for k, v in gc_content.items():
    if best_label == "":
        best_label = k
        best_content = v
    else:
        if (
            best_content.numerator * v.denominator
            < best_content.denominator * v.numerator
        ):
            best_label = k
            best_content = v

print(best_label)
print(f"{100 * best_content.numerator / best_content.denominator}%")
