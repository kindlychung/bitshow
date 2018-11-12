#ifndef bitshow_HPP
#define bitshow_HPP

#include <bitset>
#include <cstring>
#include "details.hpp"
#include "ieee_format.hpp"
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

floating_formats::format<double> anatomy(double x);
floating_formats::format<float> anatomy(float x);

}  // namespace bitshow

#endif
