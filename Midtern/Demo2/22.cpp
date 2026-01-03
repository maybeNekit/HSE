#include <iostream>
#include <string>

class Shape {
private:
    std::string name;
public:
    Shape(std::string n): name(n){};
    auto getName() {
        return name;
    }
    void setName(std::string a) {
        name = a;
    }
    void print() {
        std::cout << "Shape: " << name;
    }
    friend std::ostream& operator<<(std::ostream& os, Shape& s) {
        os << "Shape" << s.name;
        return os;
    }
};

class ShapeCollection {
private:
    std::vector<Shape> shapes;
public:
    void add(const std::string &a) {
        Shape s(a);
        shapes.emplace_back(s);
    }
    void printAll() const {
        for ( auto i:shapes) {
            i.print();
        }
    }
};

int main() {
    // Shape s{"circle"};
    // s.print();
    // std::string a;
    // std::cin >> a;
    // s.setName(a);
    // s.print();
    ShapeCollection s;
    std::string a;
    while (std::cin >> a) {
        s.add(a);
    }
    s.printAll();


    return 0;
}