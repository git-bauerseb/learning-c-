#include <iostream>
#include <string>
#include <stdexcept>
#include <typeinfo>
#include <vector>
#include "type.h"

template<typename T>
class Vector {
    private:
        T* elem;
        int sz;

    public:
        explicit Vector<T>(int s);
        Vector<T>(std::initializer_list<T> l) {
            elem = new T[l.size()];
            std::copy(l.begin(), l.end(), elem);
        }



        ~Vector() {delete[] elem;}

        T& operator[](int i) {return elem[i];}
        const T& operator[](int i) const {return elem[i];}

        int size() const {return sz;}
        T* begin();
        T* end();
};


template<typename T>
Vector<T>::Vector(int s) {
    if (s < 0) {
        throw std::invalid_argument{"Received negative size"};
    }

    elem = new T[s];
    sz = s;
}

template<typename T>
T* Vector<T>::begin() {
    return size() ? &elem[0] : nullptr;
}

template<typename T>
T* Vector<T>::end() {
    return size() ? &(elem[0 + size()]) : nullptr;
}


template<typename T, int N>
struct Buffer {
    using value_type = T;

    T buffer[N];

    constexpr int size() {return N;}
};

template<typename Container>
typename Container::value_type sum(const Container& cont) {
    typename Container::value_type total = 0;

    for (const auto& e : cont) {
        total += e;
    }

    return total;
}


int main() {

    Vector<std::string> v(3);
    v[2] = "Hello World";
    v[0] = "Alice in Wonderland";
    v[1] = "Beadle the Bard";

    for(auto& s : v) {
        std::cout << s << "\n";
    }

    Vector<char> vc(200);

    Buffer<char, 1024> buffer{};
    buffer.buffer[10] = 'A';

    // Only works in >= C++ 17
    // Vector vs {"Hello", "World"};
    // std::cout << demangle(typeid(vs).name()) << "\n";   // Vector<char const*>

    // Deduction type
    // Vector v1 {1,2,3,4,5};
    // Vector v2{v1.begin(), v1.begin() + 2};

    std::vector<int> some_numbers{1,2,3,4,5,6,7,8,9};
    int s = sum(some_numbers);
    std::cout << s << "\n";

    return 0;
}