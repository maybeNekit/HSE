#include <iostream>

class Number {
private:
    int value;
public:
    Number(int x) : value(x) {}

    int getValue() const {
        return value;
    }

    void setValue(int a) {
        value = a;
    }

    void print() const {
        std::cout << "Number: " << value << "\n";
    }
};

class numberCollection {
private:
    std::vector<Number> data;
public:
    void add(int v) {
        data.emplace_back(v);
    }
    void printAll() {
        for (auto i : data) {
            i.print();
        }
    }
};



int main() {
    int b;
    if (std::cin >> b) {
        Number n{b};
        n.setValue(5);
        n.print();
    }
    std::cout << '\n';
    numberCollection nu;
    nu.add(10);
    nu.add(5);
    nu.printAll();

    return 0;
}