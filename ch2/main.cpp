#include <iostream>
#include <variant>

/*
struct Vector {
    int sz;
    double* elem;
};

void vector_init(Vector& v, int s) {
    v.elem = new double[s];
    v.sz = s;
}

double read_and_sum(int s) {
    Vector v;
    vector_init(v,s);

    for (int i = 0; i != s; ++i) {
        std::cin >> v.elem[i];
    }

    double sum = 0;

    for (int i = 0; i != s; ++i) {
        sum += v.elem[i];
    }

    return sum;
}
*/

class Vector {
    public:
        Vector(int s) : elem{new double[s]}, sz{s} {}
        double& operator[](int i) {return elem[i];} // Element access

        int size() const {return sz;}

    private:
        double* elem;
        int sz;
};

double read_and_sum(int s) {
    Vector v{s};

    for (int i = 0; i != v.size(); ++i) {
        std::cin >> v[i];
    }

    double sum = 0;
    for (int i = 0; i != v.size(); ++i) {
        sum += v[i];
    }

    return sum;
}

/*
struct Node {

};

enum Type {ptr, num};
union Value {
    Node* p;
    int i;
};

struct Entry {
    string name;
    std::variant<Node*, int> v;
};

void f(Entry* pe) {
    if (std::holds_alternative<int>(pe->v)) {
        std::cout << std::get<int>(pe->v);
    }
}
*/

enum class TrafficLight {
    red, yellow, green
};

TrafficLight& next(TrafficLight& t) {
        switch (t) {
        case TrafficLight::green: return t = TrafficLight::yellow;
        case TrafficLight::yellow: return t = TrafficLight::red;
        case TrafficLight::red: return t = TrafficLight::green;
        default: return t = TrafficLight::green;
    }
}



int main() {
    TrafficLight n = next(TrafficLight::green);
    std::cout << n << "\n";
}