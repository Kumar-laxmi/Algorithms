#include <stdio.h>
#include <math.h>

void ShriDharacharyaFormulae(double a, double b, double c) {
    double compValue = pow(b, 2) - 4 * a * c;
    double val1 = -b / (2 * a);
    
    if (compValue >= 0) {
        double val2 = sqrt(compValue) / (2 * a);
        printf("%lf and %lf\n", val1 + val2, val1 - val2);
    } else {
        printf("Imaginary roots\n");
    }
}

int main() {
    double a, b, c;
    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);
    ShriDharacharyaFormulae(a, b, c);
    return 0;
}
