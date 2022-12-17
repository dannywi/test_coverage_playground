#include <iostream>
#include <type_traits>

using namespace std;

namespace m {

namespace in {
template <typename T>
constexpr typename enable_if<is_integral<T>::value, bool>::type bigger(T a, T b) {
    return a > b;
}

template <typename T, typename = typename enable_if<is_floating_point<T>::value, void>::type>
constexpr T EPS() {
    return 1e-6;
}

template <typename T>
constexpr typename enable_if<is_floating_point<T>::value, bool>::type bigger(T a, T b) {
    return (a - b) > EPS<T>();
}
}  // namespace in

template <typename T>
bool bigger(T a, T b) {
    return in::bigger(a, b);
}

template <typename T>
bool bigger2(T a, T b) {
    if constexpr (is_floating_point<T>::value) {
        return (a - b) > in::EPS<T>();
    }
    return a > b;
}
}  // namespace m

int main(int argc, char* argv[]) {
    cout << "... test " << m::bigger(1, 2) << endl;
    cout << "... test " << m::bigger(3.2, 2.0) << endl;
    cout << "... test " << m::bigger2(3.2, 2.0) << endl;
    if (argc > 2) {
        auto ato_ = atof;
        cout << "... test " << m::bigger2(ato_(argv[1]), ato_(argv[2])) << endl;
    }
}
