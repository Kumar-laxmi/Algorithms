# Josephus Problem Algorithm ::
# 1. Create a list to represent the circle of people, numbered from 1 to n.
# 2. Start with an index variable pointing to the first person.
# 3. Repeat the elimination process until only one person remains:
#     a. Move the index k-1 steps in a circular manner.
#     b. Remove the person at the current index.
#     c. Update the index to the next position after the elimination, wrapping around if necessary.
# 4. Return the value of the last remaining person.

def josephus(n, k):
    people = list(range(1, n + 1))  # Create a list with people numbered from 1 to n
    index = 0

    # Elimination process
    while len(people) > 1:
        # Move the index k-1 steps in a circular manner
        index = (index + k - 1) % len(people)

        # Remove the person at the current index
        people.pop(index)

    return people[0]  # Return the value of the last remaining person

# User input for n and k
n = int(input("Enter the number of people in the circle: "))
k = int(input("Enter the elimination step size: "))

lastPerson = josephus(n, k)  # Solve the Josephus Problem
print("The last remaining person is at position:", lastPerson)
