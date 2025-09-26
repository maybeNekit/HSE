#include <iostream>
#include "../func.h"
#include "div.cpp"
#include "../multiply.cpp"
#include "../plus.cpp"
#include "../minus.cpp"
int main() {
    int x = 20;
    int y = 4;
    std::cout << "plus:      " << plus(x, y) << '\n';
    std::cout << "minus:     " << minus(x, y) << '\n';
    std::cout << "multiply:  " << mult(x, y) << '\n';
    std::cout << "divide:    " << divi(x, y) << '\n';

    return 0;
}