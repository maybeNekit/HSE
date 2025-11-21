


#include <iostream>
#include <cmath>
class Vector2D {
public:
    struct Polar {
        double r, angle;
    };
    double x,y;

    Vector2D(double x=0.0, double y =0.0) {
        this -> x = x;
        this -> y = y;
    };

    Vector2D& add(double dx, double dy) {
        this -> x += dx;
        this -> y += dy;
        return *this;
    }
    Vector2D& scale(double k) {
        this -> x *= k;
        this -> y *= k;
        return *this;
    }
    Polar toPolar() const {
        Polar p;
        p.r = std::sqrt(this -> x * this -> x + this -> y * this -> y);
        p.angle = std::atan2(this -> y, this ->x);
        return p;
    }

};

void printVector(const Vector2D& v) {
    std::cout << v.x << " " <<v.y << " " << '\n';
};

void printPolar(const Vector2D::Polar& p) {
    std::cout << p.r << " " <<p.angle << " " << '\n';
}

int main() {
    Vector2D v{3.0, 4.0};

    v.add(1.0, -2.0)
     .scale(2.0)
     .add(-3.0, 1.0);

    auto p = v.toPolar();

    std::cout << "В декартовой форме: ";
    printVector(v);
    std::cout << "В полярной форме: ";
    printPolar(p);
    return 0;
}