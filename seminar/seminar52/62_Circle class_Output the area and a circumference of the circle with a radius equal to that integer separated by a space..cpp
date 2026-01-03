#include <iostream>
#include <cmath>
#include <iomanip>

class Circle {
public:
    int radius;

    Circle(int r) : radius(r) {}

    double area() {
        return M_PI * radius * radius;
    }

    double circumference() {
        return 2 * M_PI * radius;
    }
};

int main() {
    int r;
    std::cin >> r;

    Circle circle(r);
    std::cout << std::fixed << std::setprecision(2)
              << circle.area() << ' ' << circle.circumference() << '\n';

    return 0;
}
