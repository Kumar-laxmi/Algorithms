"""
  ------------------------------------------------- PREREQUISITE ---------------------------------------------------------

    --> Modular Multiplicative inverse exist when two numbers are CO-PRIME to each other in other words the two numbers gcd = 1
    --> Modular Multiplicative inverse changes with respective modulo value and not remain same for the number.

  ---------------------------------------- Modulo Multiplicative Inverse(MMI) --------------------------------------------

    Inverse of a number (A) will be = A^-1 or we can say that --> A * A^-1 will be equal to 1
    but incase of modular multiplicative inverse of a number (A) is when the expression below is true

                    (A*A^-1) mod (C) = 1

    from the expression we can say that A^-1 will be the inverse of A.

    Example:-
         We have to find the Modulo Multiplicative inverse of 2 whose mod is 5
         From the formula
            (A*A^-1) mod (C) = 1 now will be --> (2*A^-1) mod (5) = 1
         we have to find the A^-1 value
         simply we can use a loop to iterate upto the mod value and find the inverse by the below method
            (2*A^-1) mod (5) = 1 now,
           --> (2*1)%5 = 2 which is not equal to 1 so increment
           --> (2*2)%5 = 4 which is not equal to 1 so increment
           --> (2*1)%5 = 1 which is equal to 1 so,
           for the number 2 the modular multiplicative inverse will be 3 when modulo is 5. If modulo changes the modulo multiplicative
           inverse changes.

  ------------------------------------------- The Problem Statement ------------------------------------------------------

   Given two numbers, the first one is the number which we want to find the modulo multiplicative inverse and
   the second one is the modulo value

   INPUT :- 2 <-- number which we want to find modulo multiplicative inverse
            5 <-- the respective modulo value

   OUTPUT :- 3

  ---------------------------------------- The Problem of normal approach ------------------------------------------------

    To find mmi we can simply use a for loop starting from 0 to value of mod in-between the mmi exist a BigO(n) approach,
    it is good for small numbers,the problem starts when the modulo is increased lets say the value of modulo is 21783,
    in this case the loop runs for 21783 times to find the mmi in worst case which takes a huge time to compute for that
    we go for an algorithm called the EXTENDED EUCLIDEAN ALGORITHM to find the mmi which takes BigO(log(n)) time which is
    a significant reduction in time complexity, log(21783) = 4.338 so the loop at worst case itself runs 4 times only.

  ------------------------------------------ Extended Euclidean Algorithm ------------------------------------------------

    a.x + b.y = gcd                      --(1)

    And x1 and y1 are results for inputs b%a and a
    (b%a).x1 + a.y1 = gcd

    When we put b%a = (b – ([b/a]).a) in above,
    we get following. Note that [b/a] is floor(b/a)
    (b – ([b/a]).a).x1 + a.y1  = gcd

    Above equation can also be written as below
    b.x1 + a.(y1 – ([b/a]).x1) = gcd      --(2)

    After comparing coefficients of ‘a’ and ‘b’ in (1) and (2), we get following,
    x = y1 – (b/a) * x1
    y = x1

  ----------------------------------------------- Complexities -----------------------------------------------------------

    Time Complexity  --> BigO(log(n))
    Space Complexity --> BigO(1)
    Space Complexity --> BigO(n) --> In case of recursion.

"""
# Declaring the needed variables
res =0
quotient =0
gcd =0
remainder =0

# The function that execute the Extended Euclidean Algorithm
def mmi(number, modulo):
    # Declaring variables as global so that we can use anywhere else in the program.
    global t1
    global t2

    # BASE CASE of the Recursion
    if number == 0:
        t1 =0
        t2 =1
        return modulo

    # Finding the remainder of the number with modulo
    remainder = modulo%number

    # Recursively calling the function to find gcd so we can say that the mmi exist or not.
    gcd = mmi(remainder,number)

    # Finding the quotient of the number with modulo
    quotient = modulo // number

    # The Extended Euclidean Algorithm
    # To find the value of mmi
    t = t1
    t1 = t2 - quotient*t1
    t2 = t

    # Returning the gcd to check whether the inverse exist or not
    return gcd

# Alerting the user about the characteristics of the numbers
print("TO FIND MMI THE TWO NUMBERS SHOULD BE CO-PRIME TO EACH OTHER OR THE GCD OF TWO NUMBERS SHOULD BE EQUAL TO 1")
print("OTHERWISE THE INVERSE DOESN'T EXIST")

# Reading the number which user want to find inverse
number = int(input("Enter the number you want to find inverse = "))

# Reading the modulo value from the user
modulo =int(input("Enter modulo value = "))

# Calling the recursive function.
ans = mmi(number,modulo)

# gcd!=1 --> If gcd is not equal to 1 then inverse doesn't exist
if ans !=1:
    print("Inverse doesn't exist because they are not co-primes to each other")
else:
    # Computing the value of Modular multiplicative inverse
    # t1 is negative --> t1 = t1+modulo
    # t1 is positive --> print t1 no problem
    # Since it takes another if statement inside this else statement we can use the below operation to combine the results.
    res = (t1%modulo + modulo)%modulo
    print("The inverse of the number",number,"is", res,"when modulo is", modulo)
