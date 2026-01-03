#include <iostream>

class Dist {
private:
    int meters;
public:
    Dist(int m):meters(m){};

    int getMeters() {
        return meters;
    }

    void setMeters(int a) {
        meters=a;
    }

    void print() {
        std::cout <<"Distance: " << meters << " m";
    }
};

int main() {
    int n;
    std::cin >> n;
    Dist d(n);
    d.print();

    return 0;
}