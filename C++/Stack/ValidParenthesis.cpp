#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to check if the parentheses in a string are balanced
bool isValid(string s) {
    stack<char> st; // Stack to store opening parentheses

    for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') {
            // If the character is an opening parenthesis, push it onto the stack
            st.push(ch);
        } else {
            if (ch == ')') {
                // If the character is a closing parenthesis ')', check if the stack is empty or the top of the stack does not match the corresponding opening parenthesis '('
                if (st.empty() || st.top() != '(') {
                    return false; // Unbalanced parentheses
                }
                st.pop(); // Pop the corresponding opening parenthesis from the stack
            } else if (ch == '}') {
                // Similar check for closing parenthesis '}'
                if (st.empty() || st.top() != '{') {
                    return false; // Unbalanced parentheses
                }
                st.pop(); // Pop the corresponding opening parenthesis from the stack
            } else if (ch == ']') {
                // Similar check for closing parenthesis ']'
                if (st.empty() || st.top() != '[') {
                    return false; // Unbalanced parentheses
                }
                st.pop(); // Pop the corresponding opening parenthesis from the stack
            }
        }
    }

    return st.empty(); // The parentheses are balanced if the stack is empty after processing all characters
}

int main() {
    string s = "{}()[]";
    if (isValid(s)) {
        cout << "Valid parentheses" << endl;
    } else {
        cout << "Invalid parentheses" << endl;
    }
    return 0;
}
