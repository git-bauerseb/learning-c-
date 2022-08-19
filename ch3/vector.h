#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>

class Vector {
    public:
        Vector(int s);
        double& operator[](int i);
        int size();

    private:
        double* elem;
        int sz;
};

#endif