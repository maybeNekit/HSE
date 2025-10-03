#include <iostream>

int main() {
    int a , b;
    int *pa = &a;
    int *pb = &b;
    std::cin >> a >> b;
    *pa += *pb * 2;
    *pb = *pa - 2* *pb;
    *pa = (*pa - *pb)/2;
    std::cout <<*pa << " " << *pb;
    return 0;
}