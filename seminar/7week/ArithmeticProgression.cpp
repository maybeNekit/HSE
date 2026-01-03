#include <iostream>
#include <stdexcept>

class ArithmeticProgression {
private:
    double start;
    double step;
    int size;

public:
    ArithmeticProgression(double x, double y, int z): start(x), step(y), size(z){};
    ArithmeticProgression() : ArithmeticProgression(0,1,10){};

    int getSize() const {
        return size;
    }

    int operator[](int index) const {
        if ((index < 0)||(index > size)) {
            throw std::out_of_range("out_of_range");
        }
        return start + index*step;
    }
};
int main() {
    ArithmeticProgression st(0,1,10);
    std::cout << st.getSize() << "\n";
    std::cout << st[3];
    return 0;
}