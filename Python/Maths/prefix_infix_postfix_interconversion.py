#!/usr/bin/env python

"""Expression Interconversion

This script provides a menu-driven interface to demonstrate interconversion
between different notations for arithmetic expressions i.e., Prefix, Infix
and Postfix.

Python: 3.10.8

External packages: None

Author: Siddhant Tiwari (github.com/stiwari-ds)
"""

import sys


def priority_level(operator: str) -> int:
    match operator:
        case "+":
            return 1
        case "-":
            return 1
        case "*":
            return 2
        case "/":
            return 2
        case "^":
            return 3
        case _:
            return -1  # invalid operator


def prefix_to_infix(prefix: str) -> str:
    infix = []

    for char in reversed(prefix):  # parsing right to left
        if char.isalpha():  # operand
            infix.append(char)
        else:  # operator
            left_operand = infix.pop()
            right_operand = infix.pop()
            infix.append(f"({left_operand} {char} {right_operand})")

    return infix.pop()


def infix_to_prefix(infix: str) -> str:
    prefix = []
    operator_stack = []

    for char in infix:
        if char == "(":
            operator_stack.append(char)
        elif char == ")":
            # pop triplets until '(' is found
            while operator_stack and operator_stack[-1] != "(":
                right_operand = prefix.pop()
                left_operand = prefix.pop()
                operator = operator_stack.pop()
                prefix.append(operator + left_operand + right_operand)
            operator_stack.pop()  # remove pending '('
        elif char.isalpha():  # operand directly added to output
            prefix.append(char)
        else:  # operator
            # pop operators until lower precedence operator is found
            while operator_stack and (
                priority_level(char) <= priority_level(operator_stack[-1])
            ):
                right_operand = prefix.pop()
                left_operand = prefix.pop()
                operator = operator_stack.pop()
                prefix.append(operator + left_operand + right_operand)
            operator_stack.append(char)

    while operator_stack:  # pop remaining triplets
        right_operand = prefix.pop()
        left_operand = prefix.pop()
        operator = operator_stack.pop()
        prefix.append(operator + left_operand + right_operand)

    return prefix.pop()


def infix_to_postfix(infix: str) -> str:
    postfix = []
    operator_stack = []

    for char in infix:
        if char.isalpha():  # operand directly added to output
            postfix.append(char)
        elif char == "(":  # pushed into stack
            operator_stack.append(char)
        elif char == ")":  # pop operators until '(' is encountered
            while operator_stack and operator_stack[-1] != "(":
                postfix.append(operator_stack.pop())  # popped char added to output
            operator_stack.pop()  # remove pending '('
        else:  # operator
            # pop operators until lower precedence operator is found
            while operator_stack and (
                priority_level(char) <= priority_level(operator_stack[-1])
            ):
                postfix.append(operator_stack.pop())
            operator_stack.append(char)

    while operator_stack:  # pop remaining operators
        postfix.append(operator_stack.pop())

    return "".join(postfix)


def postfix_to_infix(postfix: str) -> str:
    infix = []

    for char in postfix:
        if char.isalpha():  # operand
            infix.insert(0, char)
        else:  # operator
            right_operand = infix.pop(0)
            left_operand = infix.pop(0)
            infix.insert(0, f"({left_operand} {char} {right_operand})")

    return infix.pop()


def postfix_to_prefix(postfix: str) -> str:
    prefix = []

    for char in postfix:
        if char.isalpha():  # operand
            prefix.append(char)
        else:  # operator
            right_operand = prefix.pop()
            left_operand = prefix.pop()
            prefix.append(char + left_operand + right_operand)

    return "".join(prefix)


def prefix_to_postfix(prefix: str) -> str:
    postfix = []

    for char in reversed(prefix):  # parsing right to left
        if char.isalpha():  # operand
            postfix.append(char)
        else:
            left_operand = postfix.pop()
            right_operand = postfix.pop()
            postfix.append(left_operand + right_operand + char)

    return "".join(postfix)


def menu_interface():
    menu = (
        "\n---- Expression Interconversion ----\n"
        "ID    OPERATION\n"
        "1. Prefix to Infix\n"
        "2. Infix to Prefix\n"
        "3. Infix to Postfix\n"
        "4. Postfix to Infix\n"
        "5. Postfix to Prefix\n"
        "6. Prefix to Postfix\n"
        "0. Exit\n"
    )

    while True:
        print(menu)
        try:
            choice = int(input("Enter operation ID: ").strip())
        except ValueError:
            print("Invalid ID entered. Try again.")
            continue

        match choice:
            case 1:
                prefix = input("Enter prefix expression: ").strip()
                infix = prefix_to_infix(prefix)
                print(f"Infix conversion: {infix}")
            case 2:
                infix = input("Enter infix expression: ").strip()
                prefix = infix_to_prefix(infix)
                print(f"Prefix conversion: {prefix}")
            case 3:
                infix = input("Enter infix expression: ").strip()
                postfix = infix_to_postfix(infix)
                print(f"Postfix conversion: {postfix}")
            case 4:
                postfix = input("Enter postfix expression: ").strip()
                infix = postfix_to_infix(postfix)
                print(f"Infix conversion: {infix}")
            case 5:
                postfix = input("Enter postfix expression: ").strip()
                prefix = postfix_to_prefix(postfix)
                print(f"Prefix conversion: {prefix}")
            case 6:
                prefix = input("Enter prefix expression: ").strip()
                postfix = prefix_to_postfix(prefix)
                print(f"Postfix conversion: {postfix}")
            case 0:  # Exit
                sys.exit("\nExiting.")
            case _:
                print("Invalid ID entered. Try again.")

        _ = input("\nPress enter to continue...")


if __name__ == "__main__":
    menu_interface()
