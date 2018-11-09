#pragma once
#include <bitset>

namespace floating_formats {
template <typename A>
struct format {};
struct format<double> {
    std::bitset<1> sign;
    std::bitset<11> exponent;
    std::bitset<52> mantissa;
};

struct format<float> {
    std::bitset<1> sign;
    std::bitset<8> exponent;
    std::bitset<23> mantissa;
};
}  // namespace floating_formats