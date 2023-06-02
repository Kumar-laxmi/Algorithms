class Stack:
    def __init__(self):
        self.stack = []  # List to store the elements of the stack

    def push(self, data):
        self.stack.append(data)  # Add an element to the top of the stack

    def pop(self):
        if not self.is_empty():
            return self.stack.pop()  # Remove and return the top element of the stack
        else:
            print("Stack is empty.")
            return None

    def is_empty(self):
        return len(self.stack) == 0  # Check if the stack is empty

def is_valid(s):
    stack = Stack()  # Create a stack object

    for ch in s:
        if ch == '(' or ch == '{' or ch == '[':
            stack.push(ch)  # If the character is an opening parenthesis, push it onto the stack
        else:
            if ch == ')':
                if stack.is_empty() or stack.pop() != '(':  # If the character is a closing parenthesis ')', check if the stack is empty or the top of the stack does not match the corresponding opening parenthesis '('
                    return False  # Unbalanced parentheses
            elif ch == '}':
                if stack.is_empty() or stack.pop() != '{':  # Similar check for closing parenthesis '}'
                    return False  # Unbalanced parentheses
            elif ch == ']':
                if stack.is_empty() or stack.pop() != '[':  # Similar check for closing parenthesis ']'
                    return False  # Unbalanced parentheses

    return stack.is_empty()  # The parentheses are balanced if the stack is empty after processing all characters

s = "{}()[]"
if is_valid(s):
    print("Valid parentheses")
else:
    print("Invalid parentheses")
