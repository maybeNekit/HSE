#include <iostream>

int main() {
    int a;
    std::cin >> a;
    if (a/1000 == a%10) {
        std::cout << ((((a/100)%10) == ((a/10)%10)) ? 1 : 0);
    } else {
        std::cout << ((a/100) == (a%10) ? 1 : 0);
    }
    return 0;
}