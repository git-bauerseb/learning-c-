#include "vector.h"
#include <iostream>
#include <complex>

namespace My_code {
    class complex {

    };
}

using namespace std;

int main() {
    Vector v{-7};
    // std::cout << v.size() << "\n";

    // Throws exception
    try {
        std::cout << v[10] << "\n";
    } catch (std::out_of_range& err) {
        std::cerr << err.what() << "\n";
    }
}
