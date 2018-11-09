#ifndef bitshow_HPP
#define bitshow_HPP
#include <bitset>

template <class T>
struct float_double_integral {
    static constexpr bool value = std::is_same<float, T>::value ||
                                  std::is_same<double, T>::value ||
                                  std::is_integral<T>::value;
};

static_assert(sizeof(float) == 4);
static_assert(sizeof(double) == 8);
static_assert(
    sizeof(float) <= sizeof(long long unsigned int),
    "bitshow requires that sizeof(float) <= sizeof(unsigned long long)");

namespace bitshow {

unsigned long const float_sign_mask = 0b10000000000000000000000000000000;
unsigned long const float_exponent_mask = 0b01111111100000000000000000000000;
unsigned long const float_mantissa_mask = 0b00000000011111111111111111111111;
unsigned long const double_sign_mask =
    0b1000000000000000000000000000000000000000000000000000000000000000;
unsigned long const double_exponent_mask =
    0b0111111111110000000000000000000000000000000000000000000000000000;
unsigned long const double_mantissa_mask =
    0b0000000000001111111111111111111111111111111111111111111111111111;

namespace details {
template <unsigned nbits>
struct uint {};
template <>
struct uint<8> {
    using type = uint8_t;
};
template <>
struct uint<16> {
    using type = uint16_t;
};
template <>
struct uint<32> {
    using type = uint32_t;
};
template <>
struct uint<64> {
    using type = uint64_t;
};
}  // namespace details

template <class T>
using unsigned_integer_of_same_size =
    typename details::uint<sizeof(T) * 8>::type;

using uint_equiv_float = unsigned_integer_of_same_size<float>;
using uint_equiv_double = unsigned_integer_of_same_size<double>;

template <typename A>
std::bitset<sizeof(A) * 8> bits(A x) {
    static_assert(float_double_integral<A>::value);
    unsigned_integer_of_same_size<A> x_as_uint = 0;
    std::memcpy(&x_as_uint, &x, sizeof(A));
    std::bitset<B> x_bits(x_as_uint);
    return x_bits;
}

}  // namespace bitshow

#endif
