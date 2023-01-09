# Approach :- 
# we have to loop and find the non primes first
# for ex:- lets say number is 10
# prime number are - 2,3,5....
# sqrt(10) = around 3 we check multiples here like 
# starting with 2 -> we have 4,6,8,10 we mark these places as false
# now next 3 ->  we have 9 we mark it as false
# hence we got all non-prime marked false
def sieveOfErastosthenes(n, sieve):
    # creating a list of boolean act as sieve initially all places is true
    isPrime = [True]*(n+1)
    p = 2
    # iterating through the square root of number and finding all non-prime numbers
    while p*p <= n:
        if isPrime[p]:
            i = p * p
    # marking the place as false here 
            while i <= n:
                isPrime[i] = False
                i += p
        p += 1
    # adding the result to list here
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
