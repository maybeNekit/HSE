#include <iostream>

int main() {
    double a,b;
    std::cin >> a>>b;
    double* pn =&a;
    *pn = b;
    std::cout << a;
    return 0;
}