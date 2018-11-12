#pragma once

static_assert(sizeof(float) == 4);
static_assert(sizeof(double) == 8);
static_assert(
    sizeof(float) <= sizeof(long long unsigned int),
    "bitshow requires that sizeof(float) <= sizeof(unsigned long long)");

template <class T>
struct float_double_integral {
    static constexpr bool value = std::is_same<float, T>::value ||
                                  std::is_same<double, T>::value ||
                                  std::is_integral<T>::value;
};

template <class T>
using unsigned_integer_of_same_size =
    typename details::uint<sizeof(T) * 8>::type;
