#include <iostream>
#include <vector>

template <int N>
struct Factorial {
    static int const value = N * Factorial<N-1>::value;
};

template <>
struct Factorial<1> {
    static int const value = 1;
};


template<typename T>
struct removeConst<const T> {
    typedef T type;
};

int main() {
    const std::vector<int>& a {1,2,3,4};

    removeConst<const std::vector<int>>

    a[2] = 40;

    std::cout << a[2] << "\n";

    return 0;
}