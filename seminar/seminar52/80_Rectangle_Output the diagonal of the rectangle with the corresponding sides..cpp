#include <iostream>
#include <cmath>
#include <iomanip>

class Rectangle {
private:
    int width;
    int height;

public:
    Rectangle(int w, int h) : width(w), height(h) {}

    double diagonal() {
        return std::sqrt(width * width + height * height);
    }
};

int main() {
    int w, h;
    std::cin >> w >> h;

    Rectangle rect(w, h);
    double diag = rect.diagonal();

    std::cout << std::fixed << std::setprecision(6) << diag << std::endl;

    return 0;
}