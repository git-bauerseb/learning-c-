#include <iostream>
#include <vector>

class A  {
    public:
        virtual void foo() =0;
};

class B : public A {
    public:
        virtual void foo() override {
            std::cout << "HELLO WORLD";
        }
};

int main() {

    std::vector<A*> v{new B(), new B()};
    
    v[0]->foo();

    return 0;
}