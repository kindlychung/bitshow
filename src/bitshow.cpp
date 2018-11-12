#include "bitshow.hpp"
#include "details.hpp"
#include "masks.hpp"
#include "types.hpp"

namespace bitshow {
floating_formats::format<double> anatomy(double x) {
    auto x_bits = bits(x);
    std::bitset<1> sign_bit(
        ((x_bits & masks::double_sign_mask) >> 63).to_ullong());
    std::bitset<11> exponent_bits(
        ((x_bits & masks::double_exponent_mask) >> 52).to_ullong());
    std::bitset<52> mantissa_bits(
        (x_bits & masks::double_mantissa_mask).to_ullong());
    floating_formats::format<double> result{sign_bit, exponent_bits,
                                            mantissa_bits};
    return result;
}

floating_formats::format<float> anatomy(float x) {
    auto x_bits = bits(x);
    std::bitset<1> sign_bit(
        ((x_bits & masks::float_sign_mask) >> 63).to_ullong());
    std::bitset<8> exponent_bits(
        ((x_bits & masks::float_exponent_mask) >> 52).to_ullong());
    std::bitset<23> mantissa_bits(
        (x_bits & masks::float_mantissa_mask).to_ullong());
    floating_formats::format<float> result{sign_bit, exponent_bits,
                                           mantissa_bits};
    return result;
}
}