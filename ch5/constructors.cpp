#include <iostream>
#include <string>

class Complex {
    double re = 0;      // Default initializer
    double im = 0;

    public:
        Complex(double r, double i) : re{r}, im{i} {}
        Complex(double r) : re{r} {}
        Complex() {}
};

class Vector {
    private:
        double* elem;
        int sz;

    public:
        Vector(int s) : sz{s}, elem{new double[s]} {}
        ~Vector() {
            delete[] elem;
        }

        Vector(const Vector& a);                // Copy constructor
        Vector& operator=(const Vector& a) {    // Copy assignment
            double* p = new double[a.sz];

            for (int i = 0; i < a.sz; i++) {
                p[i] = a.elem[i];
            }

            delete[] elem;

            elem = p;
            sz = a.sz;


            return *this;
        }

        Vector(Vector&& a) {                    // Move constructor
            std::cout << "Move constructor called\n";
        }                     

        Vector& operator=(Vector&& a) {         // Move assignment
            std::cout << "Move assignment called\n";
        }


        double& operator[](int i) {return elem[i];}
        const double& operator[](int i) const;

        int size() const {return sz;}
};

Vector::Vector(const Vector& a) : elem{new double[a.sz]}, sz{a.sz}{
    for (int i = 0; i < sz; i++) {
        elem[i] = a.elem[i];
    }

    std::cout << "Called copy constructor\n";
}

int main(int argc, char** argv) {

    // std::vector<float> v{8};
    Vector v1{10}, v2{3};
    v2 = v1;    // Copy assignment
    std::cout << v2.size() << "\n";

    Vector v3 {4};

    v3 = std::move(v2);

    std::cout << "123"s << "\n";


    return 0;
}