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
2. In custom mode, you must specify your equation in the code at line 162.
3. ** is not valid as power in c++ due to syntax issues.
*/

#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

// =========================================================
// EXPRESSION EVALUATOR CODE
// =========================================================

// Calculator: Performs arithmetic calculations based on operator
float calculator(float v1, float v2, string action) {
    if (action == "**" || action == "^") {
        float res = 1;
        for(int i = 1; i < v2 + 1; i++) {
            res = res * v1;
        }
        return res;
    }
    else if (action == "*") {
        return v1 * v2;
    }
    else if (action == "/") {
        return v1 / v2;
    }
    else if (action == "+") {
        return v1 + v2;
    }
    else if (action == "-") {
        return v1 - v2;
    }
    else {
        cout << "\n\tInvalid operator\t\n";
        exit(1);
    }
}

// Solves sub-expressions by performing operations in a specific order
void solveSubExpression(vector<string>& expression, string operand) {
    int j = 0;
    while (j < expression.size()) {
        if (expression[j] == operand) {
            float val = calculator(stof(expression[j - 1]), stof(expression[j + 1]), expression[j]);
            expression.erase(expression.begin() + j - 1);
            expression.erase(expression.begin() + j);
            expression[--j] = to_string(val);
        }
        else {
            j++;
        }
    }
}

// Solves the given equation using expression evaluator
string solve(string eq) {
    // Breaking the expression into vector list.
    vector<string> expression;
    string exp_val = "";
    for (auto i: eq) {
        if (i == '+' || i == '-' || i == '*' || i == '/' || i == '^') {
            expression.push_back(exp_val);
            expression.push_back(std::string(1, i));
            exp_val = "";
        }
        else {
            exp_val = exp_val + i;
        }
    }
    expression.push_back(exp_val);
    
    // Solving the expressions based on BODMAS rule
    solveSubExpression(expression, "^");
    solveSubExpression(expression, "/");
    solveSubExpression(expression, "*");
    solveSubExpression(expression, "+");
    solveSubExpression(expression, "-");
    
    return expression[0];
}

// Evaluates the equation by replacing variables and calling the expression evaluator
float evaluate(string eq, float val = 0) {
    // First remove the empty spaces
    // and replace 'x' with 'val'
    // and '**' with '^'
    for (int i = 0; i < eq.length(); i++) {
        if (eq[i] == ' ') {
            eq.erase(i, 1);
        }
        if (eq[i] == 'x') {
            eq.replace(i, 1, to_string(val));
        }
        if ((i < eq.length() - 1) && (eq[i] == '*') && (eq[i + 1] == '*')) {
            eq.replace(i, 2, "^");
        }
    }
    
    // Solving the brackets first.
    int strt = 0, end = 0, i = 0;
    while (i < eq.length()) {
        if (eq[i] == '(') {
            strt = i;
        }
        if (eq[i] == ')') {
            end = i;
        }
        
        if (strt != end && end != 0) {
            string res = solve(eq.substr(strt + 1, end - strt - 1));
            eq.replace(strt, end - strt + 1, res);
            i = 0;
            strt = 0;
            end = 0;
        }
        else {
            i++;
        }
        
    }
    return stof(solve(eq));
}

// ================================================
// BISECTION CODE
// ================================================

// Response class to store the result of bisection method
class Response {
public:
    string remarks;
    float ans;
    string status;
};

// The function for which we need to find the root
float f(float x, const string& mode = "default", const string& eq = "") {
    float result = 0;
    
    if (mode == "default") {
        result = evaluate(eq, x);
    }
    else {
        // Place your equation here
        result = x*x - 20*x + 100;
    }
    
    return result;
}

// Bisection method implementation
Response solveBisection(float low_lim, float up_lim, int iter, const string& mode, const string& eq) {
    Response res_obj;
    
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
    if (f(low_lim, mode, eq) * f(up_lim, mode, eq) < 0) {
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
        }
        else if (res < 0) {
            low_lim = x;
        }
        else {
            res_obj.status = "found";
            res_obj.ans = x;
            res_obj.remarks = "iteration: " + to_string(i);
            break;
        }
        
        x = (low_lim + up_lim) / 2;
    }
    if (res_obj.status != "found") {
        res_obj.status = "searching";
        res_obj.ans = x;
        res_obj.remarks = "nearest answer";
    }
    return res_obj;
}

int main() {
    cout << "*************************************\n";
    cout << "* NOTE:-                            *\n";
    cout << "* Do read the multi-line comments   *\n";
    cout << "* before executing                  *\n";
    cout << "*************************************\n";
    string m, eq;
    float low_lim, up_lim;
    int iter;
    
    cout << "Mode (custom/default) (leave blank for default): ";
    getline(cin, m);
    if (m == "") {
        m = "default";
        cout << "Enter the equation (in x): ";
        getline(cin, eq);
    }
    else if (m != "custom") {
        cout << "This mode doesn't exist" << endl;
        exit(1);
    }
    
    cout << "Lower Limit: ";
    cin >> low_lim;
    cout << "Upper Limit: ";
    cin >> up_lim;
    cout << "Iterations: ";
    cin >> iter;
    
    Response res_obj = solveBisection(low_lim, up_lim, iter, m, eq);
    
    cout << "\nStatus: " << res_obj.status;
    cout << "\nAnswer: " << res_obj.ans;
    cout << "\nRemarks: " << res_obj.remarks;
    
    return 0;
}
