#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

class BaseShape {
public:
    virtual ~BaseShape() = default;
    virtual void print() const = 0;
    virtual double getArea() const = 0;
};

class Shape : public BaseShape {
private:
    std::string name;
    double area;
public:
    Shape(std::string n, double a) : name(n), area(a) {}

    double getArea() const override {
        return area;
    }

    void print() const override {
        std::cout << "Shape: " << name;
    }
};

class Circle : public BaseShape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    double getArea() const override {
        return M_PI * radius * radius;
    }

    void print() const override {
        std::cout << "Circle with radius " << radius;
    }
};

class Rectangle : public BaseShape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double getArea() const override {
        return width * height;
    }

    void print() const override {
        std::cout << "Rectangle " << width << " x " << height;
    }
};

class ShapeCollection {
private:
    std::vector<BaseShape*> shapes;
public:
    void add(BaseShape* shape) {
        shapes.push_back(shape);
    }

    void printAll() const {
        for (const auto* shape : shapes) {
            shape->print();
            std::cout << " " << shape->getArea() << std::endl;
        }
    }

    ~ShapeCollection() {
        for (auto* shape : shapes) {
            delete shape;
        }
        shapes.clear();
    }
};

int main() {
    std::cout << std::fixed << std::setprecision(2);

    ShapeCollection c;
    c.add(new Shape("Triangle", 12.5));
    c.add(new Circle(3.0));
    c.add(new Rectangle(4.0, 5.0));

    c.printAll();

    return 0;
}