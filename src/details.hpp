#pragma once
#include <cstdint>

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