// ====================== Problem Statement ==========================
// Modified By : Anubha Sharma
// Github UserName: AnubhaSharma2709
/*
Menu-Driven application to convert->
1.Infix to Postfix
2.Infix to Prefix
3.Prefix to Postfix
4.Prefix to Infix
5.Postfix to Prefix
6.Postfix to Infix

Algorithm -

--- Infix to Postfix---
1)Scan the infix expression from left to right. 
2)If the scanned character is an operand, append it to postfix variable. 
  Else, 
3)If the precedence of the scanned operator are greater than the precedence of the operator on top of the stack(or the stack is empty or the stack contains a ‘(‘ ), then push it.
4)Else,
  Pop all the operators from the stack which are greater than or equal to in precedence than that of the scanned operator. After doing that Push the scanned operator to the stack. (If you encounter parenthesis while popping then stop there and push the scanned operator in the stack.) 
5)If the scanned character is an ‘(‘, push it to the stack. 
6)If the scanned character is an ‘)’, pop the stack and output it until a ‘(‘ is encountered, and discard both the parenthesis. 
7)Repeat until the infix expression is scanned. 
8)Pop and append from the stack until it is not empty.
9)Return the postfix var 


--- Infix to Prefix---
1) Reverse the infix expression,while reversing each ‘(‘ will become ‘)’ and each ‘)’ becomes ‘(‘.
2) Apply postfix converison of the modified expression.
3) Reverse the postfix expression.


---Prefix to Postfix/Infix---
1)Read the Prefix expression from right to left
2)If the element is an operand, then push it onto the Stack
  If the element is an operator, then pop two operands from the Stack 
3)Create a string as shown below- 
string = operand1 + operand2 + operator (Prefix to Postfix) 
string = operand1 + operator + operand2(Prefix to Infix) 

push the resultant string to Stack
4)The remaining string at top of stack is the required expression.


---Postix to Prefix/Infix---
1)Read the Postfix expression.
2)If the element is an operand, then push it onto the Stack
  If the element is an operator, then pop two operands from the Stack 
3)Create a string as shown below-
string = operator + operand1 + operand2 (Postfix to Prefix) 
string = operand1 + operator + operand2 (Postfix to Infix) 

push the resultant string back to Stack
4)The remaining string at top of stack is the required expression.
*/

// // ====================== Code with Java ==========================


import java.util.*;

class Stack {
    private int top;
    private int capacity;
    private char[] array;

    public Stack(int capacity) {
        this.capacity = capacity;
        this.top = -1;
        this.array = new char[capacity];
    }

    public boolean isEmpty() {
        return top == -1;
    }

    public char peek() {
        return array[top];
    }

    public char pop() {
        if (!isEmpty()) {
            return array[top--];
        }
        return '$';
    }

    public void push(char op) {
        array[++top] = op;
    }
}

class Conversion {
    public static boolean isOperand(char ch) {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
    }

    public static boolean isOperator(char ch) {
        return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
    }

    public static int precedence(char ch) {
        if (ch == '^')
            return 3;
        else if (ch == '*' || ch == '/')
            return 2;
        else if (ch == '+' || ch == '-')
            return 1;
        else
            return -1;
    }

    public static String infixToPostfix(String exp) {
        StringBuilder postfix = new StringBuilder();
        Stack stack = new Stack(exp.length());

        for (int i = 0; i < exp.length(); ++i) {
            char c = exp.charAt(i);
            if (isOperand(c)) {
                postfix.append(c);
            } else if (c == '(') {
                stack.push(c);
            } else if (c == ')') {
                while (!stack.isEmpty() && stack.peek() != '(') {
                    postfix.append(stack.pop());
                }
                if (!stack.isEmpty() && stack.peek() != '(') {
                    return "Invalid Expression";
                } else {
                    stack.pop();
                }
            } else {
                while (!stack.isEmpty() && precedence(c) <= precedence(stack.peek())) {
                    postfix.append(stack.pop());
                }
                stack.push(c);
            }
        }

        while (!stack.isEmpty()) {
            postfix.append(stack.pop());
        }

        return postfix.toString();
    }

    public static String infixToPrefix(String exp) {
        StringBuilder prefix = new StringBuilder();
        Stack stack = new Stack(exp.length());
        Stack resultStack = new Stack(exp.length());

        for (int i = 0; i < exp.length(); ++i) {
            char c = exp.charAt(i);
            if (c == '(') {
                stack.push(c);
            } else if (c == ')') {
                while (!stack.isEmpty() && stack.peek() != '(') {
                    resultStack.push(stack.pop());
                }
                if (!stack.isEmpty() && stack.peek() != '(') {
                    return "Invalid Expression";
                } else {
                    stack.pop();
                }
            } else if (isOperand(c)) {
                resultStack.push(c);
            } else {
                while (!stack.isEmpty() && precedence(c) <= precedence(stack.peek())) {
                    resultStack.push(stack.pop());
                }
                stack.push(c);
            }
        }

        while (!stack.isEmpty()) {
            resultStack.push(stack.pop());
        }

        while (!resultStack.isEmpty()) {
            prefix.append(resultStack.pop());
        }

        return prefix.toString();
    }

    public static String prefixToPostfix(String exp) {
        StringBuilder postfix = new StringBuilder();
        Stack stack = new Stack(exp.length());

        for (int i = exp.length() - 1; i >= 0; --i) {
            char c = exp.charAt(i);
            if (isOperand(c)) {
                stack.push(c);
            } else {
                char op1 = stack.pop();
                char op2 = stack.pop();
                postfix.append(op1);
                postfix.append(op2);
                postfix.append(c);
            }
        }

        return postfix.toString();
    }

    public static String prefixToInfix(String exp) {
        StringBuilder infix = new StringBuilder();
        Stack stack = new Stack(exp.length());

        for (int i = exp.length() - 1; i >= 0; --i) {
            char c = exp.charAt(i);
            if (isOperand(c)) {
                stack.push(c);
            } else {
                char op1 = stack.pop();
                char op2 = stack.pop();
                infix.append('(');
                infix.append(op1);
                infix.append(c);
                infix.append(op2);
                infix.append(')');
            }
        }

        return infix.toString();
    }

    public static String postfixToPrefix(String exp) {
        StringBuilder prefix = new StringBuilder();
        Stack stack = new Stack(exp.length());

        for (int i = 0; i < exp.length(); ++i) {
            char c = exp.charAt(i);
            if (isOperand(c)) {
                stack.push(c);
            } else {
                char op2 = stack.pop();
                char op1 = stack.pop();
                prefix.append(c);
                prefix.append(op1);
                prefix.append(op2);
            }
        }

        return prefix.toString();
    }

    public static String postfixToInfix(String exp) {
        StringBuilder infix = new StringBuilder();
        Stack stack = new Stack(exp.length());

        for (int i = 0; i < exp.length(); ++i) {
            char c = exp.charAt(i);
            if (isOperand(c)) {
                stack.push(c);
            } else {
                char op2 = stack.pop();
                char op1 = stack.pop();
                infix.append('(');
                infix.append(op1);
                infix.append(c);
                infix.append(op2);
                infix.append(')');
            }
        }

        return infix.toString();
    }
}

public class ExpressionConversion {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String exp;
        int choice;

        System.out.print("Enter expression: ");
        exp = scanner.nextLine();

        while (true) {
            System.out.println("---------------------------------------");
            System.out.println("Press 1 for Infix to Postfix conversion");
            System.out.println("Press 2 for Infix to Prefix conversion");
            System.out.println("Press 3 for Prefix to Postfix conversion");
            System.out.println("Press 4 for Prefix to Infix conversion");
            System.out.println("Press 5 for Postfix to Prefix conversion");
            System.out.println("Press 6 for Postfix to Infix conversion");
            System.out.println("Press 0 to exit");
            choice = scanner.nextInt();
            scanner.nextLine();

            switch (choice) {
                case 1:
                    System.out.println("Postfix Expression: " + Conversion.infixToPostfix(exp));
                    break;
                case 2:
                    System.out.println("Prefix Expression: " + Conversion.infixToPrefix(exp));
                    break;
                case 3:
                    System.out.println("Postfix Expression: " + Conversion.prefixToPostfix(exp));
                    break;
                case 4:
                    System.out.println("Infix Expression: " + Conversion.prefixToInfix(exp));
                    break;
                case 5:
                    System.out.println("Prefix Expression: " + Conversion.postfixToPrefix(exp));
                    break;
                case 6:
                    System.out.println("Infix Expression: " + Conversion.postfixToInfix(exp));
                    break;
                case 0:
                    System.exit(0);
            }
        }
    }
}
