#include <bitshow.h>
#include <ieee_format.h>
#include <bitset>
#include <iomanip>
#include <iostream>

void print_double(double x) {
    auto x_components = bitshow::anatomy(x);
    std::cout << std::fixed << std::setprecision(4);
    std::cout << x << " in binary: ";
    std::cout << x_components.sign << " ";
    std::cout << x_components.exponent << " ";
    std::cout << x_components.mantissa << "\n";
}

int main() {
    double x = -7.0;  // (-1)^1 * (1 + 2^-1 + 2^-2) * 2^2
    print_double(x);
    return 0;
}