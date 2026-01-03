#include <iostream>
#include <vector>

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

class SquaredNumber : public BaseNumber {
private:
    int value;
public:
    SquaredNumber(int v):value(v*v){};
    void print() const override{
        std::cout << "SquaredNumber:" << value << '\n';
    }
    int getValue() const override {
        return value;
    }
};

class DoubleNumber : public BaseNumber {
private:
    int value;
public:
    DoubleNumber(int v):value(2*v){};
    void print() const override{
        std::cout << "DoubleNumber:" << value << '\n';
    }
    int getValue() const override {
        return value;
    }
};



class numberCollection {
private:
    std::vector<BaseNumber*> data;
public:
    void add(BaseNumber* n) {
        data.emplace_back(n);
    }

    void printAll() {
        for (const auto i : data) {
            i->print();
        }
    }

    ~numberCollection() {
        for (auto item : data) {
            delete item;
        }
    }
};

int main() {
    numberCollection c;
    c.add(new Number(3));
    c.add(new SquaredNumber(4));
    c.add(new DoubleNumber(5));
    c.printAll();
    return 0;
}