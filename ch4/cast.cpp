#include <iostream>

class A {
    public:
        virtual void some_func() {
            std::cout << "A";
        }
};

class B : public A {
    public:
        virtual void some_func() override {
            std::cout << "B";
        }
};

int main() {
    A* a = new A();

    B& b {dynamic_cast<B&>(*a)};

    // True if a is of type B
    /*
    if (b) {
        std::cout << "a is of type B\n";
    } else {
        std::cout << "a is not of type B\n";
    }
    */

    return 0;
}