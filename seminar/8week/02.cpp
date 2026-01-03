#include <iostream>
#include <string>
#include <cmath>
#include <vector>

class Shape {
protected:
    std::string name;
public:
    Shape (std::string n): name(n) {}
    virtual double area () const {
        return (0.0);
    }
    virtual void printInfo () const {
        std::cout << name << '\n';
    }
    virtual ~Shape() {}
};
class Rectangle:public Shape {
private:
    double width;
    double height;
public:
    Rectangle (const std::string& n, double w, double h): Shape(n), width(w), height(h) {}
    double area() const override {
        return (width*height);
    }
    void printInfo()  const override{
        std::cout << "width: " << width << " " << "height: " << height << '\n';
    }
};
class Circle : public Shape {
private:
    double radius;
public:
    Circle(const std::string& n, double r): Shape(n), radius(r) {}
    double area() const  override{
        return M_PI * radius * radius;
    }
    void printInfo() const override{
        std::cout << "radius: " << radius << '\n';
    }
};

void printShapeDetails(const Shape& s) {
    s.printInfo();
    std::cout << s.area() << '\n';
}

int main() {
    Rectangle rect("MyRectangle", 3.0, 4.0);
    Circle circ("MyCircle", 5.0);
   // rect.printInfo();
    //std::cout << "area: " << rect.area() << "\n\n";
    //circ.printInfo();
    //std::cout << "area: " << circ.area() << "\n";
    printShapeDetails(rect);
    printShapeDetails(circ);
    Shape* shapes[2];
    shapes[0] = &rect;
    shapes[1] = &circ;
    for (auto i : shapes) {
        i->printInfo();
        std::cout << i->area();
    }

    return 0;
}
