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
2. In custom mode, you must specify your equation in the code at line 212.
3. ** is not valid as power in c++ due to syntax issues.
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
// ==========================================================
// EXPRESSION EVALUATOR
// ==========================================================

int isOperator(char c) {
    // Check if the character is one of the operators
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

float calculator(float v1, float v2, char* action) {
    // Perform the calculation based on the operator
    if (strcmp(action, "**") == 0 || strcmp(action, "^") == 0) {
        float res = 1;
        for (int i = 1; i < v2 + 1; i++) {
            res = res * v1;
        }
        return res;
    } else if (strcmp(action, "*") == 0) {
        return v1 * v2;
    } else if (strcmp(action, "/") == 0) {
        return v1 / v2;
    } else if (strcmp(action, "+") == 0) {
        return v1 + v2;
    } else if (strcmp(action, "-") == 0) {
        return v1 - v2;
    } else {
        printf("\n\tInvalid operator\n");
        exit(1);
    }
}
void solveSubExpression(char** expression, int* exp_size, char* operand) {
    int j = 0;
    int newSize = *exp_size; // New size of the expression array

    while (j < newSize) {
        if (strcmp(expression[j], operand) == 0) {
            float val = calculator(atof(expression[j - 1]), atof(expression[j + 1]), expression[j]);

            // Convert the result back to a string
            char* res = (char*)malloc(sizeof(char) * 20);
            snprintf(res, 20, "%f", val);

            // Free the memory for operands
            free(expression[j - 1]);
            free(expression[j + 1]);

            // Update the expression array
            expression[j - 1] = res;

            // Shift the remaining elements in the array
            for (int k = j + 2; k < newSize; k++) {
                expression[k - 2] = expression[k];
            }

            newSize -= 2;
            j = 0; // Reset the index to re-check from the beginning
        } else {
            j++;
        }
    }

    *exp_size = newSize; // Update the expression size
}


char* solve(char* eq) {
    // Breaking the expression into token list.
    char** expression = (char**)malloc(sizeof(char*) * 20);
    int exp_size = 0;
    char exp_val[20] = "";
    int j = 0;
    for (int i = 0; eq[i] != '\0'; i++) {
        if (isOperator(eq[i])) {
            expression[exp_size] = strdup(exp_val);
            exp_size++;

            // Convert the operator character to a string
            char op[2];
            op[0] = eq[i];
            op[1] = '\0';

            expression[exp_size] = strdup(op);
            exp_size++;

            // Reset the expression value
            strcpy(exp_val, "");
            j = 0;
        } else {
            // Append the character to the expression value
            exp_val[j++] = eq[i];
        }
    }

    // Add the last number to the expression
    expression[exp_size] = strdup(exp_val);
    exp_size++;

    // Going as per the BODMAS
    solveSubExpression(expression, &exp_size, "^");
    solveSubExpression(expression, &exp_size, "/");
    solveSubExpression(expression, &exp_size, "*");
    solveSubExpression(expression, &exp_size, "+");
    solveSubExpression(expression, &exp_size, "-");

    char* result = strdup(expression[0]);

    // Free the memory for the expression array
    for (int i = 0; i < exp_size; i++) {
        free(expression[i]);
    }
    free(expression);

    return result;
}

float evaluate(const char* eq, float val) {
    // First remove the empty spaces and replace 'x' with 'val'
    char modifiedEq[100] = "";  // Initialize modifiedEq as an empty string
    int index = 0;
    
    for (int i = 0; i < strlen(eq); i++) {
        if (eq[i] == ' ') {
            continue;  // Skip empty spaces
        } else if (eq[i] == 'x') {
            // Convert the value to a string
            char temp[20];
            snprintf(temp, sizeof(temp), "%.2f", val);  // Using "%.2f" for two decimal places
    
            // Append the value to modifiedEq
            strcat(modifiedEq, temp);
            index += strlen(temp);
        } else if (i < strlen(eq) - 1 && eq[i] == '*' && eq[i + 1] == '*') {
            modifiedEq[index++] = '^';  // Replace '**' with '^'
            i += 1;  // Skip the next '*'
        } else {
            modifiedEq[index++] = eq[i];  // Copy non-space characters to modifiedEq
        }
    }
    modifiedEq[index] = '\0';  // Add null terminator to indicate the end of the string


    // Solving the brackets first.
    int start = 0, end = 0, i = 0;
    while (i < strlen(modifiedEq)) {
        if (modifiedEq[i] == '(') {
            start = i;
        }
        if (modifiedEq[i] == ')') {
            end = i;
        }
    
        if (start != end && end != 0) {
            char subExpression[100];
            strncpy(subExpression, modifiedEq + start + 1, end - start - 1);
            subExpression[end - start - 1] = '\0';
            
            char* res = solve(subExpression);
            strcpy(modifiedEq + start, res);
            strcpy(modifiedEq + start + strlen(res), modifiedEq + end + 1);
            
            i = 0;
            start = 0;
            end = 0;
        } else {
            i++;
        }
    }

    return atof(solve(modifiedEq));
}

// ==========================================================
// BI SECTION CODE
// ==========================================================
// Response struct to store the result of bisection method
typedef struct {
    char* remarks;
    float ans;
    char* status;
} Response;

// The function for which we need to find the root
float f(float x, const char* mode, const char* eq) {
    float result = 0;

    if (strcmp(mode, "default") == 0) {
        result = evaluate(eq, x);
    }
    else {
        // Place your equation here
        result = x * x - 20 * x + 100;
    }

    return result;
}

// Bisection method implementation
Response solveBisection(float low_lim, float up_lim, int iter, const char* mode, const char* eq) {
    Response res_obj;

    // Pre-checkings
    if (f(low_lim, mode, eq) == 0) {
        res_obj.remarks = strdup("Starting limit");
        res_obj.ans = low_lim;
        res_obj.status = strdup("found");
        return res_obj;
    }
    if (f(up_lim, mode, eq) == 0) {
        res_obj.remarks = strdup("Ending limit");
        res_obj.ans = up_lim;
        res_obj.status = strdup("found");
        return res_obj;
    }
    if (f(low_lim, mode, eq) * f(up_lim, mode, eq) < 0) {
        res_obj.remarks = strdup("Root doesn't exist");
        res_obj.ans = 0;
        res_obj.status = strdup("not found");
        return res_obj;
    }

    res_obj.status = strdup("searching");
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
            res_obj.status = strdup("found");
            res_obj.ans = x;
            res_obj.remarks = (char*)malloc(sizeof(char) * 20);
            sprintf(res_obj.remarks, "iteration: %d", i);
            break;
        }

        x = (low_lim + up_lim) / 2;
    }
    if (!res_obj.status) {
        res_obj.status = strdup("searching");
        res_obj.ans = x;
        res_obj.remarks = strdup("nearest answer");
    }
    return res_obj;
}

int main() {
    printf("*************************************\n");
    printf("* NOTE:-                            *\n");
    printf("* Do read the multi-line comments   *\n");
    printf("* before executing                  *\n");
    printf("*************************************\n");

    char m[10], eq[100];
    float low_lim, up_lim;
    int iter;

    printf("Mode(custom/default) (leave blank for default): ");
    fgets(m, sizeof(m), stdin);
    m[strcspn(m, "\n")] = '\0';

    if (strcmp(m, "") == 0) {
        strcpy(m, "default");
        printf("Enter the equation (in x): ");
        fgets(eq, sizeof(eq), stdin);
        eq[strcspn(eq, "\n")] = '\0';
    }
    else if (strcmp(m, "custom") != 0) {
        printf("This mode doesn't exist\n");
        return 1;
    }

    printf("Lower Limit: ");
    scanf("%f", &low_lim);
    printf("Upper Limit: ");
    scanf("%f", &up_lim);
    printf("Iterations: ");
    scanf("%d", &iter);

    Response res_obj = solveBisection(low_lim, up_lim, iter, m, eq);

    printf("\nStatus: %s\n", res_obj.status);
    printf("Answer: %f\n", res_obj.ans);
    printf("Remarks: %s\n", res_obj.remarks);

    free(res_obj.remarks);
    free(res_obj.status);

    return 0;
}