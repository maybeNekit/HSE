#include <iostream>

int main() {
    int a, b,s;
    std::cin >> a >> b;
    std::cout << a <<" "<<b<<'\n';

    //a = a+2*b;
    //b = a- 2*b;
    //a = (a-b)/2;
    //std::cout << a <<" "<< b <<'\n';
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    std::cout << a <<" "<< b <<'\n';
    return 0;
}