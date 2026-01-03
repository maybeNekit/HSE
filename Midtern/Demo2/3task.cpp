#include <iostream>

class BaseNumber {
public:
    virtual ~BaseNumber() = default;
    virtual void print() const = 0;
    virtual int getValue() const = 0;
};

class Number : public BaseNumber {
private:
    int value;
public:
    Number(int v = 0) : value(v) {}

    int getValue() const override {
        return value;
    }

    void setValue(int a) {
        value = a;
    }

    void print() const override {
        std::cout << "Number: " << value << "\n";
    }
};

int main() {
    Number n;
    n.setValue(42);
    n.print();

    return 0;
}