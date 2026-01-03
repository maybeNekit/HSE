#include <iostream>

int main() {
    float y;
    std::cin >> y;

    float* p = &y;

    std::cin >> y;

    std::cout << *p << std::endl;

    return 0;
}
