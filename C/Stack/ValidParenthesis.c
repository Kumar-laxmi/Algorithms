#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Node structure for the stack
typedef struct {
    char data;
    struct Node* next;
} Node;

// Stack structure
typedef struct {
    Node* top;
} Stack;

// Function to create a new stack
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

// Function to push an element onto the stack
void push(Stack* stack, char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop an element from the stack
char pop(Stack* stack) {
    // Check if the stack is empty
    if (stack->top == NULL) {
        printf("Stack is empty.\n");
        return '\0';
    }

    char data = stack->top->data;
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

// Function to check if the stack is empty
bool isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Function to validate parentheses in a string
bool isValid(char* s) {
    Stack* stack = createStack();

    // Iterate through each character in the string
    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            // If the character is an opening parenthesis, push it onto the stack
            push(stack, ch);
        } else {
            if (ch == ')') {
                // If the character is a closing parenthesis, check if the stack is empty or the top of the stack does not match the corresponding opening parenthesis
                if (isEmpty(stack) || pop(stack) != '(') {
                    return false;
                }
            }
            if (ch == '}') {
                if (isEmpty(stack) || pop(stack) != '{') {
                    return false;
                }
            }
            if (ch == ']') {
                if (isEmpty(stack) || pop(stack) != '[') {
                    return false;
                }
            }
        }
    }

    // Check if the stack is empty after processing all characters
    return isEmpty(stack);
}

int main() {
    char s[] = "{}()[]";
    if (isValid(s)) {
        printf("Valid parentheses\n");
    } else {
        printf("Invalid parentheses\n");
    }
    return 0;
}
