def modulorExponentation(base,power,modulo):
    # Update base if it is more than or equal to modulo
    base = base % modulo
    # Initializing the result variable to store the modular exponentiation value.
    result = 1
    while power>0:
        # If power is odd, multiply base with result
        if (power & 1) != 0:
        	result = (result * base) % modulo
        # Power must be even now
        # power = power/2 	
        power = power >> 1
        base = (base * base) % modulo
    # Printing the modular exponentiation value.
    print("Modular Exponentiation = ", result)

# Reading the base,power,modulo values from the user.
base = int(input("Enter the base value = "))
power = int(input("Enter the power value = "))
modulo = int(input("Enter the modulo value = "))
# In case base is divisible by modulo
if base == 0:
    	print("0")
# Calling the function to perform the modular exponentiation.
modulorExponentation(base,power,modulo)
