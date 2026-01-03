#include <iostream>
using namespace std;

class Rectangle {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double perimeter() {
        return 2 * (width + height);
    }

    void print() {
        cout << "Width: " << width << ", Height: " << height << endl;
    }
};

int main() {
    Rectangle rect1(4, 5);
    rect1.print();
    cout << "Perimeter: " << rect1.perimeter() << endl;

    Rectangle rect2(2.5, 3.5);
    rect2.print();
    cout << "Perimeter: " << rect2.perimeter() << endl;

    return 0;
}