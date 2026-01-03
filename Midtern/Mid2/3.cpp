#include <iostream>
#include <vector>

// class Dist {
// private:
//     int meters;
// public:
//     Dist(int m):meters(m){};
//
//     int getMeters() {
//         return meters;
//     }
//
//     void setMeters(int a) {
//         meters=a;
//     }
//
//     void print() {
//         std::cout <<"Distance: " << meters << " m";
//     }
// };
//
// class Seq {
// private:
//     std::vector<int> values;
// public:
//     void add(int m) {
//         values.emplace_back(m);
//     }
//
//     int size() {
//         return values.size();
//     }
//
//     int at(int index) {
//         return values[index];
//     }
//
//     void print() {
//         for (const auto& v:values) {
//             std::cout << "Distance: " << v << " m" << '\n';
//         }
//     }
// };

class Base {
public:
    virtual ~Base() = default;
    virtual int apply(int x) const =0;
    virtual void print(int x) const =0;
};

class First : public Base {
private:
    int a;
public:
    First(int v): a(v){};
    int apply(int x) const override {
        return a+x;
    }

    void print(int x) const override {
        std::cout << x << " -> " << apply(x) << '\n';
    }

};

class Second : public Base {
private:
    const Base* a;
public:
    Second(const Base* t): a(t){};
    int apply(int x) const override {
        int fi = a->apply(x);
        return a-> apply(fi);
    }

    void print(int x) const override {
        std::cout << x << " -> " << apply(x) << '\n';
    }

};

int main() {
    int x;
    int y;
    std::cin >> x >> y;
    First* t1 = new First(x);
    Second* t2 = new Second(t1);

    std::vector<Base*> Base;
    Base.push_back(t1);
    Base.push_back(t2);

    int sum = 0;
    for (const auto* t: Base) {
        t->print(y);
        sum += t->apply(y);
    }
    std::cout << sum <<'\n';
    delete t2;
    delete t1;
    return 0;
}