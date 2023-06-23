/*
This code aims to solve the bi-section method.

Consists of two parts:-
1. Expression Evaluator
2. Bi Section solver

Limitations of Expression Evaluator:-
1. Expression Evaluator is a bit too complex.
2. cases like 5*-4 where two operators with no value in between raises and error

Limitations of Bi Section solver:-
1. In default mode all the Limitations of Expression Evaluator will apply.
2. In custom mode, you must specify your equation in the code at line 142.
3. ** is not valid as power in c++ due to syntax issues.
*/

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class bisection {
    // =========================================================
    // EXPRESSION EVALUATOR CODE
    // =========================================================

    // Calculator: Performs arithmetic calculations based on operator
    public static float calculator(float v1, float v2, String action) {
        if (action.equals("**") || action.equals("^")) {
            float res = 1;
            for (int i = 1; i < v2 + 1; i++) {
                res = res * v1;
            }
            return res;
        } else if (action.equals("*")) {
            return v1 * v2;
        } else if (action.equals("/")) {
            return v1 / v2;
        } else if (action.equals("+")) {
            return v1 + v2;
        } else if (action.equals("-")) {
            return v1 - v2;
        } else {
            System.out.println("\n\tInvalid operator\t\n");
            System.exit(1);
            return 0; // To satisfy the compiler, this line will never be executed.
        }
    }

    // Solves sub-expressions by performing operations in a specific order
    public static void solveSubExpression(List<String> expression, String operand) {
        int j = 0;
        while (j < expression.size()) {
            if (expression.get(j).equals(operand)) {
                float val = calculator(Float.parseFloat(expression.get(j - 1)), Float.parseFloat(expression.get(j + 1)), expression.get(j));
                expression.remove(j - 1);
                expression.remove(j);
                expression.set(--j, Float.toString(val));
            } else {
                j++;
            }
        }
    }

    // Solves the given equation using expression evaluator
    public static String solve(String eq) {
        // Breaking the expression into a list.
        List<String> expression = new ArrayList<>();
        String exp_val = "";
        for (char c : eq.toCharArray()) {
            if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
                expression.add(exp_val);
                expression.add(Character.toString(c));
                exp_val = "";
            } else {
                exp_val = exp_val + c;
            }
        }
        expression.add(exp_val);

        // Solving the expressions based on BODMAS rule
        solveSubExpression(expression, "^");
        solveSubExpression(expression, "/");
        solveSubExpression(expression, "*");
        solveSubExpression(expression, "+");
        solveSubExpression(expression, "-");

        return expression.get(0);
    }

    // Evaluates the equation by replacing variables and calling the expression evaluator
    public static float evaluate(String eq, float val) {
        // First remove the empty spaces
        // and replace 'x' with 'val'
        // and '**' with '^'
        eq = eq.replace(" ", "");
        eq = eq.replace("x", Float.toString(val));
        eq = eq.replace("**", "^");

        // Solving the brackets first.
        int strt = 0, end = 0, i = 0;
        while (i < eq.length()) {
            if (eq.charAt(i) == '(') {
                strt = i;
            }
            if (eq.charAt(i) == ')') {
                end = i;
            }

            if (strt != end && end != 0) {
                String res = solve(eq.substring(strt + 1, end));
                eq = eq.substring(0, strt) + res + eq.substring(end + 1);
                i = 0;
                strt = 0;
                end = 0;
            } else {
                i++;
            }
        }
        return Float.parseFloat(solve(eq));
    }

    // ================================================
    // BISECTION CODE
    // ================================================

    // Response class to store the result of the bisection method
    static class Response {
        public String remarks;
        public float ans;
        public String status = "searching";
    }

    // The function for which we need to find the root
    public static float f(float x, String mode, String eq) {
        float result = 0;

        if (mode.equals("default")) {
            result = evaluate(eq, x);
        } else {
            // Place your equation here
            result = x * x - 20 * x + 100;
        }

        return result;
    }

    // Bisection method implementation
    public static Response solveBisection(float low_lim, float up_lim, int iter, String mode, String eq) {
        Response res_obj = new Response();

        // Pre-checkings
        if (f(low_lim, mode, eq) == 0) {
            res_obj.remarks = "Starting limit";
            res_obj.ans = low_lim;
            res_obj.status = "found";
            return res_obj;
        }
        if (f(up_lim, mode, eq) == 0) {
            res_obj.remarks = "Ending limit";
            res_obj.ans = up_lim;
            res_obj.status = "found";
            return res_obj;
        }
        if (f(low_lim, mode, eq) * f(up_lim, mode, eq) > 0) {
            res_obj.remarks = "Root doesn't exist";
            res_obj.ans = 0;
            res_obj.status = "not found";
            return res_obj;
        }

        float x = (low_lim + up_lim) / 2;
        for (int i = 0; i < iter; i++) {
            float res = f(x, mode, eq);

            if (res > 0) {
                up_lim = x;
            } else if (res < 0) {
                low_lim = x;
            } else {
                res_obj.status = "found";
                res_obj.ans = x;
                res_obj.remarks = "iteration: " + Integer.toString(i);
                break;
            }

            x = (low_lim + up_lim) / 2;
        }
        if (!res_obj.status.equals("found")) {
            res_obj.status = "searching";
            res_obj.ans = x;
            res_obj.remarks = "nearest answer";
        }
        return res_obj;
    }

  public static void main(String[] args) {
        System.out.println("*************************************");
        System.out.println("* NOTE:-                            *");
        System.out.println("* Do read the multi-line comments   *");
        System.out.println("* before executing                  *");
        System.out.println("*************************************");
        Scanner scanner = new Scanner(System.in);
        String m, eq = "";
        float low_lim, up_lim;
        int iter;

        System.out.print("Mode (custom/default) (leave blank for default): ");
        m = scanner.nextLine();
        if (m.equals("")) {
            m = "default";
            System.out.print("Enter the equation (in x): ");
            eq = scanner.nextLine();
        } else if (!m.equals("custom")) {
            System.out.println("This mode doesn't exist");
            System.exit(1);
            return;
        }

        System.out.print("Lower Limit: ");
        low_lim = scanner.nextFloat();
        System.out.print("Upper Limit: ");
        up_lim = scanner.nextFloat();
        System.out.print("Iterations: ");
        iter = scanner.nextInt();

        Response res_obj = solveBisection(low_lim, up_lim, iter, m, eq);

        System.out.println("\nStatus: " + res_obj.status);
        System.out.println("Answer: " + res_obj.ans);
        System.out.println("Remarks: " + res_obj.remarks);
    }
}