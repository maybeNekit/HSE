#include <iostream>
int main() {
    int a, i, b;
    std::cin >> a >> i;
    b = 1<<i;
    std::cout << (a^b);
    return 0;
}

//0000 0101 = 5
//0000 0111 = 7
