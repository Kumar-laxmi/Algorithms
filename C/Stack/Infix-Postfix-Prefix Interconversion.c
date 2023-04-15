/* Name : Abhinav kumar
Github username : Abhinavcode13
Repository name : Algorithms
Problem Description : Infix-Postfix-Prefix Interconversion
Issue Number : 287

Infix Expression : A + B * C + D
Prefix Expression : + + A * B C D
Postfix Expression : A B C * + D +
*/

//Implementation in c of the above program

/* ->In this program I have we define a Stack struct to represent a stack of characters.
   ->Other functions used such as push, pop, and peek.
   ->defined a function precedence to determine the precedence of an operator.
   
ALGORITHMS :

1)Initialize an empty stack.
2)Iterate through each character in the input expression.
3)If the character is a digit, append it to the output string.
4)If the character is a left parenthesis, push it onto the stack.
5)If the character is a right parenthesis, pop all operators from the stack and append them to the output string until a left parenthesis is encountered. Discard the left parenthesis.
6)If the character is an operator, pop all operators from the stack that have equal or higher precedence and append them to the output string. Push the current operator onto the stack.
  Once all characters have been processed, pop any remaining operators from the stack and append them to the output string.
*/

-------------------------------------------------------------------------//C code begins here---------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char stack[MAX_SIZE];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int is_empty(Stack *s) {
    return s->top == -1;
}

int is_full(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

void push(Stack *s, char c) {
    if (is_full(s)) {
        printf("Error: stack is full\n");
        exit(1);
    }
    s->stack[++s->top] = c;
}

char pop(Stack *s) {
    if (is_empty(s)) {
        printf("Error: stack is empty\n");
        exit(1);
    }
    return s->stack[s->top--];
}

char peek(Stack *s) {
    if (is_empty(s)) {
        printf("Error: stack is empty\n");
        exit(1);
    }
    return s->stack[s->top];
}

int precedence(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void infix_to_postfix(char *infix, char *postfix) {
    Stack s;
    init(&s);
    int i, j;
    char c;
    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        c = infix[i];
        if (c >= '0' && c <= '9') {
            postfix[j++] = c;
        } else if (c == '(') {
            push(&s, c);
        } else if (c == ')') {
            while (peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s); // discard the left parenthesis
        } else {
            while (!is_empty(&s) && precedence(c) <= precedence(peek(&s))) {
                postfix[j++] = pop(&s);
            }
            push(&s, c);
        }
    }
    while (!is_empty(&s)) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}

void infix_to_prefix(char *infix, char *prefix) {
    Stack s;
    init(&s);
    int i, j, len;
    char temp[MAX_SIZE];
    strcpy(temp, infix);
    len = strlen(temp);
    for (i = 0; i < len/2; i++) {
        char t = temp[i];
        temp[i] = temp[len-1-i];
        temp[len-1-i] = t;
    }
    for (i = 0, j = 0; temp[i] != '\0'; i++) {
        if (temp[i] == '(') {
            temp[i] = ')';
        } else if (temp[i] == ')') {
            temp[i] = '(';
        }
    }
    infix_to_postfix(temp, prefix);
    len = strlen(prefix);
    for (i = 0; i < len/2; i++) {
        char t = prefix[i];
        prefix[i] = prefix[len-1-i];
        prefix[len-1-i] = t;
    }
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];
    char prefix[MAX_SIZE];

    printf("Enter an arithmetic expression in infix notation: ");
    fgets(infix, MAX_SIZE, stdin);

    infix_to_postfix(infix, postfix);
    printf("Postfix notation: %s\n", postfix);

    infix_to_prefix(infix, prefix);
    printf("Prefix notation: %s\n", prefix);

    return 0;
}
