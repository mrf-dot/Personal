def valid_triangle(a, b, c):
    return not (a < 0
            or b < 0
            or c < 0
            or a + b < c
            or a + c < b
            or b + c < a)
