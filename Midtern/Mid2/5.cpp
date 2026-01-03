#include <iostream>
#include <vector>
#include <string>

class D2 {
protected:
    std::string name;
public:
    D2(std::string n): name(n){};
    virtual ~D2() = default;
    virtual double capacity() const {
        return 0.0;
    }
    virtual void print() const {
        std::cout << name << capacity() <<'\n';
    }
};

class B:public D2 {
    private:
        int width;
        int height;
    public:
        B(int wi, int he): D2("Box"), width(wi), height(he){};
        double capacity() const override {
            return width * height *1.0;
        }
        void print() const override {
            std::cout << "Box " << width << "x" << height <<'\n';
        }
    };

    class C:public D2 {
    private:
        int radius;
    public:
        C(int r): D2("Cylinder"), radius(r){};
        double capacity() const override {
            return 3.14* radius*radius;
        }
        void print() const override {
            std::cout << "Cylinder with r=" << radius <<'\n';
        }
    };


int main() {
    std::vector<D2*> v;
    int k,l,m;
    std::cin >> k;
    std::cin >> l;
    std::cin >> m;
    v.push_back(new B(k,k));
    v.push_back(new B(k,l));
    v.push_back(new C(m));

    double s;
    for (auto i:v) {
        i->print();
        s+=i->capacity();
    }
    std::cout << s << '\n';

    for (auto i:v) {
        delete i;
    }
    return 0;
}