#pragma once

#include <type_traits>

namespace m {

namespace in {
template <typename T>
using bool_if_int = typename std::enable_if<std::is_integral<T>::value, bool>::type;
template <typename T>
using bool_if_float = typename std::enable_if<std::is_floating_point<T>::value, bool>::type;

template <typename T>
constexpr bool_if_int<T> bigger(T a, T b) {
    return a > b;
}

template <typename T>
constexpr bool_if_int<T> smaller(T a, T b) {
    return a < b;
}

template <typename T, typename = typename std::enable_if<std::is_floating_point<T>::value, void>::type>
constexpr T EPS() {
    return 1e-6;
}

template <typename T>
constexpr bool_if_float<T> bigger(T a, T b) {
    return (a - b) > EPS<T>();
}

template <typename T>
constexpr bool_if_float<T> smaller(T a, T b) {
    return (b - a) > EPS<T>();
}

}  // namespace in

template <typename T>
constexpr bool bigger(T a, T b) {
    return in::bigger(a, b);
}

template <typename T>
constexpr bool smaller(T a, T b) {
    return in::smaller(a, b);
}

template <typename T>
constexpr bool equal(T a, T b) {
    return !bigger(a, b) && !smaller(a, b);
}

template <typename T>
bool bigger2(T a, T b) {
    if constexpr (std::is_floating_point<T>::value) {
        return (a - b) > in::EPS<T>();
    }
    return a > b;
}
}  // namespace m
