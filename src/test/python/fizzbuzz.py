def fizzbuzz(**fizz_values: int) -> None:
    for i in range(1, 101):
        fizz_string = ""
        for key, value in fizz_values.items():
            if i % value == 0:
                fizz_string += key
        if not fizz_string:
            fizz_string = str(i)
        print(fizz_string)


def traditional_fizzbuzz():
    fizzbuzz(Fizz=3, Buzz=5)


if __name__ == "__main__":
    fizzbuzz(Fizz=3, Buzz=5, Foo=7, Bar=11)
