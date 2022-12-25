#include <iostream>

#include "compare.hpp"

using std::cout;
using std::endl;

#define GT(a, b) m::bigger(a, b)
#define LT(a, b) m::smaller(a, b)

int main(int argc, char* argv[]) {
    cout << "... bigger " << m::bigger(1, 2) << endl;
    cout << "... bigger " << m::bigger(3.2, 2.0) << endl;
    cout << "... equal  " << m::equal(3.2, 2.0) << endl;
    cout << "... equal  " << m::equal(2, 2) << endl;
    cout << "... bigger " << m::bigger2(3.2, 2.0) << endl;
    cout << "... GT" << LT(3.3, 2.3) << endl;

    if (argc > 2) {
        auto ato_ = atof;
        cout << "... bigger " << m::bigger2(ato_(argv[1]), ato_(argv[2])) << endl;
    }
}
