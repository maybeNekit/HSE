#include <iostream>
#include <string>
#include <cmath>

class Shape {
protected:
    std::string name;
public:
    Shape (std::string n): name(n) {}
    double area () const {
        return (0.0);
    }
    void printInfo () const {
        std::cout << name << '\n';
    }
};
class Rectangle:public Shape {
private:
    double width;
    double height;
public:
    Rectangle (const std::string& n, double w, double h): Shape(n), width(w), height(h) {}
    double area() const {
        return (width*height);
    }
    void printInfo() {
        std::cout << "width: " << width << " " << "height: " << height << '\n';
    }
};
class Circle : public Shape {
private:
    double radius;
public:
    Circle(const std::string& n, double r): Shape(n), radius(r) {}
    double area() const {
        return M_PI * radius * radius;
    }
    void printInfo() {
        std::cout << "radius: " << radius << '\n';
    }
};
int main() {
    Rectangle rect("MyRectangle", 3.0, 4.0);
    Circle circ("MyCircle", 5.0);
    rect.printInfo();
    std::cout << "area: " << rect.area() << "\n\n";
    circ.printInfo();
    std::cout << "area: " << circ.area() << "\n";
    return 0;

}
