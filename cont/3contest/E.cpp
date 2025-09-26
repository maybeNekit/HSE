#include <iostream>

int main() {
    int a=32;
    std::cout << '\t';
    for (int i = 0; i < 16; ++i) {
        std::cout << std::uppercase << std::hex << i;
        if (i != 16 - 1) std::cout << '\t';
    }
    std::cout << '\n';
    for (int j = 2; j < 8; ++j) {
        std::cout << j << '\t';
        for (int i = 1; i < 17; ++i) {
            std::cout << char(a)<<'\t';
            a +=1;
        }
        std::cout << '\n';
    }
    return 0;
}