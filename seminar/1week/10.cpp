#include <iostream>
#include <iomanip>

int main() {
    int n=21,c;
    double b=2.78433453455445;
    std::cin >> std::oct >>c;
    std::cout << std::setprecision(3) << b << std::endl;
    std::cout << std::fixed << b << std::endl;
    std::cout << std::dec << n << std::endl;
    std::cout << std::oct << n << std::endl;
    std::cout << std::hex << n << std::endl;

    return 0;
}