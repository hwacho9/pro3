import math


def eqn2(a, b, c):
    dis = b**2 - 4 * a * c
    if dis == 0:
        x = -b / (2 * a)
        return x
    elif dis > 0:
        x1 = (-b + math.sqrt(dis)) / (2 * a)
        x2 = (-b - math.sqrt(dis)) / (2 * a)
        return x1, x2
    elif dis < 0:
        real = -b / (2 * a)
        imaginary = math.sqrt(-dis) / (2 * a)
        complex1 = complex(real, imaginary)
        complex2 = complex(real, -imaginary)
        return complex1, complex2
