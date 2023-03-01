"""
------------------------------------------- The Problem Statement ------------------------------------------------------

    INPUT :- Two numbers number1 and number2 with n digits where n is a power of 2

    OUTPUT :- The product of number1 and number2 

----------------------------------------------- Complexities ---------------------------------------------------------------

    
    Time complexity in using asterisk   = BigO(n^2)
    Time Complexity of Karatsuba Alg0   = BigO(n^1.58)

"""
# Function being called or the function executing the karatsuba function
def karatsuba(num1,num2):

  # BASE CASE of Recursion
    if(num1<10 or num2<10):
        return num1*num2

    else:
        num1_string = str(num1) # Changing to string to find the length of the number1
        num2_string = str(num2) # Changing to string to find the length of number2

        length = max(len(num1_string), len(num2_string)) # Finding max length
        half=int(length/2)  # Splitting the number into two halves we need the length to be divided by 2

        # Finding a and c i.e. the higher bits for each number
        a = int(num1_string[:-half])
        c = int(num2_string[:-half])

        # Finding b and d i.e. the lower bits for each number
        b = int(num1_string[-half:])
        d = int(num2_string[-half:])

        # Finding ac, bd and ad_plus_bc
        ac = karatsuba(a, c)
        bd = karatsuba(b, d)
        ad_plus_bc = karatsuba(a + b, c + d) - ac - bd


        return ac*10**(2 * half) + ad_plus_bc*10**(half) + bd

# The main function
a = int(input("Enter first number = "))
b = int(input("Enter second number = "))

# Calling Karatsuba function using these two numbers
print("The product of the two numbers is =",karatsuba(a,b))  