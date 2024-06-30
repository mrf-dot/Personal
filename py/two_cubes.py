#!/usr/bin/env python3
# Calculate the sums of 2 cubes in ascending order
def taxi(uniq: int, mag=100) -> list[int]:
    x: list[int] = []
    for i in range(2, mag):
        for j in range(2, mag):
            x.append(i ** 3 + j ** 3)
    x = sorted(x)
    y: list[int] = []
    for i in range(uniq):
        for j in range(len(x) - 1):
            if x[j] == x[j+1]:
                y.append(x[j])
        x = y.copy()
        y.clear()
    return x


def main() -> None:
    mag = 2000
    print((taxi(1, mag)))
    print()
    print((taxi(2, mag)))
    print()
    print((taxi(3, mag)))
    print()
    print((taxi(4, mag)))
    print()
    print((taxi(5, mag)))
    print()
    print((taxi(6, mag)))


if __name__ == "__main__":
    main()
