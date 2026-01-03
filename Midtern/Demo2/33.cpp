#include <iostream>
#include <string>

class BaseShape {
public:
    virtual ~BaseShape() = default;
    virtual void print() const =0;
    virtual double getArea() const =0;


};

class Shape : public BaseShape{
private:
    std::string name;
    double area;
public:
    Shape(std::string n, double a): name(n), area(a){};
    std::string getName() {
        return name;
    }
    double getArea() const override {
        return area;
    }
    void setName(std::string a) {
        name = a;
    }
    void print() const override {
        std::cout << "Shape: " << name;
    }
    friend std::ostream& operator<<(std::ostream& os, Shape& s) {
        os << "Shape" << s.name;
        return os;
    }
};

// class ShapeCollection {
// private:
//     std::vector<Shape> shapes;
// public:
//     void add(const std::string &a) {
//         Shape s(a);
//         shapes.emplace_back(s);
//     }
//     void printAll() const {
//         for ( auto i:shapes) {
//             i.print();
//         }
//     }
// };

int main() {
    Shape s("circle", 10);
    s.print();
    std::cout << s.getArea();

    return 0;
}