#include <iostream>

int main() {
    int a;
    std::cin >> a;
    std::cout << a << " ";
    int *p1 = &(a);
    std::string b ="True";
    while (*p1>0) {
        if (*p1%10 != *p1/10) {
            b ="False";
            break;
        }
        *p1 /= 10;
        *p1 %
    }
    std::cout << b<< std::endl;
    return 0;
}