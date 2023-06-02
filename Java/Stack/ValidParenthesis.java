import java.util.Stack;

public class ValidParenthesis {

  public static void main(String[] args) {
    String s = "{}()[]";
    System.out.println(isValid(s));
  }

  public static boolean isValid(String s) {
    Stack<Character> stack = new Stack<>(); // Create a stack to store opening parentheses

    for (char ch : s.toCharArray()) { // Iterate through each character in the input string
      if (ch == '(' || ch == '{' || ch == '[') { // If it's an opening parentheses, push it onto the stack
        stack.push(ch);
      } else {
        if (ch == ')') { // If it's a closing parentheses
          if (stack.isEmpty() || stack.pop() != '(') { // Check if stack is empty or the top of the stack is not the corresponding opening parentheses
            return false; // If it doesn't match or the stack is empty, the parentheses are not valid
          }
        }
        if (ch == '}') {
          if (stack.isEmpty() || stack.pop() != '{') {
            return false;
          }
        }
        if (ch == ']') {
          if (stack.isEmpty() || stack.pop() != '[') {
            return false;
          }
        }
      }
    }
    return stack.isEmpty(); // If the stack is empty, it means all opening parentheses have been closed properly
  }
}
