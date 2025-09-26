#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    double a, b;
    std::cin >> a >> b;
    std::cout << std::fixed << std::setprecision(2) << a*a + b*b;
    return 0;
}