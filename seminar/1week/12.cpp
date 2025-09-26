#include <iostream>

int main() {
    int a;
    std::cin >> a;
    if ((a&1)==1) {
        std::cout << "odd";
    } else {
        std::cout << "even";
    }
    return 0;
}