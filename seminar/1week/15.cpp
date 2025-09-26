#include <iostream>
#include <iomanip>
int main() {
    double a, b, c, p;
    std::cin >> a >> b >> c;
    p = (a + b + c) / 2;
    std::cout << std::fixed << std::setprecision(2) << p*(p - a)*(p - b)*(p - c);
    return 0;
}