#include <iostream>

int main() {
    int a;
    std::cin >> a;
    std::cout << a << " ";
    int *p1 = &(a);
    if (*p1<0) std::cout << "-";
    *p1 = abs(*p1);
    while (*p1>0) {
        int num = (*p1%10);
        std::cout << num;
        *p1 /= 10;
    }
    return 0;
}