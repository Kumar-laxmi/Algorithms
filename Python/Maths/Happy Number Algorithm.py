def is_happy(n):
    seen = set()

    while n != 1:
        current = n
        sum_of_squares = 0

        while current != 0:
            digit = current % 10
            sum_of_squares += digit * digit
            current //= 10

        if sum_of_squares in seen:
            return False  # Entered a cycle containing 4, so it's an unhappy number

        seen.add(sum_of_squares)
        n = sum_of_squares

    return True  # Reached 1, so it's a happy number

number = int(input("Enter a number: "))
is_happy_number = is_happy(number)
print(f"{number} is a happy number: {is_happy_number}")
