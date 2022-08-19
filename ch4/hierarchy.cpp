#include <vector>

struct P {
    int x;
};

class Shape {
    public:
        virtual P center() const =0;
        virtual void move(P to) =0;

        virtual void draw() const =0;
        virtual void rotate(int angle) =0;

        virtual ~Shape() {}
};

void rotate_all(const std::vector<Shape*>& v, int angle) {
    for (auto ptr : v) {
        ptr->rotate(angle);
    }
}


class Circle : public Shape {
    public:
        Circle(P p, int radius) : x{p}, r{radius} {};

        P center() const override {
            return x;
        }

        void move(P to) override {
            x = to;
        }

        void draw() const override;

        void rotate(int r) override {}

        ~Circle() {}

    private:
        P x;
        int r;
};

int main() {

    // std::vector<Shape*> shapes;
    P p;
    Circle c = {p, 1};

    // rotate_all(shapes, 1);

    return 0;
}