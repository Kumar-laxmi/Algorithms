def sieveOfErastosthenes(n, sieve):
    isPrime = [True]*(n+1)
    isPrime
    p = 2
    while p*p <= n:
        if isPrime[p]:
            i = p * p
            while i <= n:
                isPrime[i] = False
                i += p
        p += 1
    for j in range(2, n + 1):
        if (isPrime[j]):
            sieve.append(j)
    return sieve

def main():
    n = int(input("Enter Number - "))
    sieve = []
    sieveOfErastosthenes(n, sieve)
    print(sieve)

if __name__ == '__main__':
    main()
