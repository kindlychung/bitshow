#ifndef bitshow_HPP
#define bitshow_HPP

#include <bitset>
#include <cstring>
#include "details.hpp"
#include "ieee_format.hpp"
#include "masks.hpp"
#include "types.hpp"

namespace bitshow {

#define SIZE_A sizeof(A) * 8

template <typename A>
std::bitset<SIZE_A> bits(A x) {
    static_assert(float_double_integral<A>::value);
    unsigned_integer_of_same_size<A> x_as_uint = 0;
    std::memcpy(&x_as_uint, &x, sizeof(A));
    std::bitset<SIZE_A> x_bits(x_as_uint);
    return x_bits;
}

floating_formats::format<double> anatomy(double x) {
    auto x_bits = bits(x);
    std::bitset<1> sign_bit(
        ((x_bits & masks::double_sign_mask) >> 63).to_ullong);
    std::bitset<11> exponent_bits(
        ((x_bits & masks::double_exponent_mask) >> 52).to_ullong);
    std::bitset<52> mantissa_bits(
        (x_bits & masks::double_mantissa_mask).to_ullong);
    floating_formats::format<double> result{sign_bit, exponent_bits,
                                            mantissa_bits};
    return result;
}

floating_formats::format<float> anatomy(float x) {
    auto x_bits = bits(x);
    std::bitset<1> sign_bit(
        ((x_bits & masks::float_sign_mask) >> 63).to_ullong);
    std::bitset<8> exponent_bits(
        ((x_bits & masks::float_exponent_mask) >> 52).to_ullong);
    std::bitset<23> mantissa_bits(
        (x_bits & masks::float_mantissa_mask).to_ullong);
    floating_formats::format<float> result{sign_bit, exponent_bits,
                                           mantissa_bits};
    return result;
}

}  // namespace bitshow

#endif
