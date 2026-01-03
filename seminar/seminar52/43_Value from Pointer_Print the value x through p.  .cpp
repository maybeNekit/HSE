#include <iostream>

int main() {
    int x;
    std::cin >> x;

    int* p = &x;

    std::cout << *p << std::endl;

    return 0;
}
