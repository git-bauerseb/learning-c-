#include <iostream>
#include <complex>
#include <vector>

constexpr double nth(double x, int n) {
    double res = 1;
    int i = 0;

    while (i < n) {
        res *= x;
        i++;
    }

    return res;
}

void print() {
    int v[] = {0,1,2,3,4,5,6,7,8,9};

    for (auto x : v) {
        std::cout << x << "\n";
    }
}

void increment() {
    int v[] = {0,1,2,3,4,5,6,7,8,9};

    // Reference
    for (auto& x : v) {
        ++x;
    }
}

void sort(std::vector<double>&);
double sum(const std::vector<double>&);

int count_x(const char* p, char x) {
    if (p == nullptr) {
        return 0;
    }

    int count = 0;

    for (; *p != 0; ++p) {
        if (*p == x) {
            ++count;
        }
    }

    return count;
}

int main() {
    float a = 3.14159'26;
    int b = 124'135;

    std::cout << ~b << "\n";

    // Initialization
    std::complex<double> z = 1;
    std::complex<double> z2 {d1, d2};
    std::complex<double> z3 = {d1, d2};     // '=' optional with '{}'

    char v[6];  // Array
    char* p;    // Pointer
    

}