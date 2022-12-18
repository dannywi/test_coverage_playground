#include <iostream>

#include "compare.hpp"

using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
    cout << "... test " << m::bigger(1, 2) << endl;
    cout << "... test " << m::bigger(3.2, 2.0) << endl;
    cout << "... test " << m::bigger2(3.2, 2.0) << endl;
    if (argc > 2) {
        auto ato_ = atof;
        cout << "... test " << m::bigger2(ato_(argv[1]), ato_(argv[2])) << endl;
    }
}
