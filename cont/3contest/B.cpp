#include <iostream>

int main() {
    int a, sum=0;
    std::cin >> a;
    while (a>0) {
        sum+=a%10;
        a = a/10;
    }
    std::cout << sum;
    return 0;
}