// Defines a module
module;

// Define module called "Vector"
export module Vector;

export class Vector {
    public:
        Vector(int s);
        double& operator[](int i);
        int size();

    private:
        double* elem;
        int sz;
};

double& Vector::operator[](int i) {
    return elem[i];
}

int Vector::size() {
    return sz;
}

// Export non-member function "size"
export int size(const Vector& v) {
    return v.size();
}