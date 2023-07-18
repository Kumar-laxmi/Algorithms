#include <iostream>
#include <cmath>

void ShriDharacharyaFormulae(double a, double b, double c) {
    double compValue = pow(b, 2) - 4 * a * c;
    double val1 = -b / (2 * a);
    
    if (compValue >= 0) {
        double val2 = sqrt(compValue) / (2 * a);
        std::cout << val1 + val2 << " and " << val1 - val2 << std::endl;
    } else {
        std::cout << "Imaginary roots" << std::endl;
    }
}

int main() {
    double a, b, c;
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    ShriDharacharyaFormulae(a, b, c);
    return 0;
}
