def pythagorean_triples(n):
    return [
        (a, b, c)
        for a in range(1, n)
        for b in range(a, n)
        for c in range(b, n)
        if a**2 + b**2 == c**2
    ]


print(pythagorean_triples(20))
