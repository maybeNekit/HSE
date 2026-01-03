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

int main() {
    Shape s{"circle"};
    s.print();
    std::string a;
    std::cin >> a;
    s.setName(a);
    s.print();

    return 0;
}