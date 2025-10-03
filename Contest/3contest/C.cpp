#include <iostream>

int main() {
    int a,b;
    std::cin >> a >> b;
    std::cout << '\t';
    for (int j = 1; j <= a; ++j) {
        if (j > 1) std::cout << '\t';
        std::cout << j;
    }
    std::cout << '\n';

    for(int i = 1; i<=a; ++i) {
        std::cout << i;
        for (int j = 1; j<=a; ++j) {
            std::cout<< '\t' << i*j%b;
        }
        std::cout << '\n';
    }
    return 0;
}