#include <iostream>

int main() {
    int a;
    std::cin >> a;
    std::cout << a/1000 + a/100%10 + a/10%10 + a%10 << std::endl;
    return 0;
}