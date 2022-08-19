#include <iostream>

class Container {

    public:
        virtual double& operator[](int) =0;     // Pure virtual function
        virtual int size() const =0;            // Const member function
        virtual ~Container() {}
};

class A {
    public:
        virtual void some_function() =0;
};

class B : public A {
    
};

int main(int argc, char** argv) {

    A a;
    a.some_function();

    return 0;
}