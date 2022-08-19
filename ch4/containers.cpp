#include <initializer_list>
#include <algorithm>
#include <iostream>

class Vector {

    public:
        Vector(int s) : elem{new double[s]}, sz{s} {
            for (int i = 0; i != sz; i++) {
                elem[i] = 0;
            }

            count = 0;
        }

        Vector(std::initializer_list<double> l) : elem{new double[l.size()]},
            sz{static_cast<int>(l.size())} {
            count = static_cast<int>(l.size()) - 1;
            std::copy(l.begin(), l.end(), elem);
        }

        void push_back(double v) {
            if (count >= (sz-1)) {
                throw 1;
            }

            elem[count++] = v;
        }

        ~Vector() {
            delete[] elem;
        }

        static Vector read(std::istream& is);

        double& operator[](int i) {
            return elem[i];
        }

        int size() const {
            return sz;
        }

    private:
        double* elem;
        int count;
        int sz;
};

inline std::ostream& operator<<(std::ostream& os, Vector& v) {
    for (int i = 0; i < v.size(); i++) {
        os << v[i];
    }

    return os;
}


Vector Vector::read(std::istream& is) {
    Vector v(10);

    for (double d; is >> d;) {
        v.push_back(d);
    }

    return v;
}


int main() {

    Vector v = Vector::read(std::cin);

    std::cout << v << "\n";

    return 0;
}