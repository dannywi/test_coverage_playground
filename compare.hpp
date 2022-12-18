#pragma once

#include <type_traits>

namespace m {

namespace in {
template <typename T>
constexpr typename std::enable_if<std::is_integral<T>::value, bool>::type bigger(T a, T b) {
    return a > b;
}

template <typename T, typename = typename std::enable_if<std::is_floating_point<T>::value, void>::type>
constexpr T EPS() {
    return 1e-6;
}

template <typename T>
constexpr typename std::enable_if<std::is_floating_point<T>::value, bool>::type bigger(T a, T b) {
    return (a - b) > EPS<T>();
}
}  // namespace in

template <typename T>
bool bigger(T a, T b) {
    return in::bigger(a, b);
}

template <typename T>
bool bigger2(T a, T b) {
    if constexpr (std::is_floating_point<T>::value) {
        return (a - b) > in::EPS<T>();
    }
    return a > b;
}
}  // namespace m
