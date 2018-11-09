# Bitshow: a c++ library for dissecting floating point numbers

## Example:

```cpp
#include <bitset>
#include <bitshow.hpp>
#include <ieee_format.hpp>
#include <iostream>

void print_double(double x) {
    auto x_components = bitshow::anatomy(x);
    std::cout << x_components.sign << " ";
    std::cout << x_components.exponent << " ";
    std::cout << x_components.mantissa << "\n";
}

int main() {
    double x = -7.;  // (-1)^1 * (1 + 2^-1 + 2^-2) * 2^2
    print_double(x);
    return 0;
}
```

## Use this package

`buckaroo install github+kindlychung/bitshow`