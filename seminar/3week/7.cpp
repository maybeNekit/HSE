#include <iostream>
#include <concepts>

template <typename T>
requires(std::integral<T> || std::floating_point<T>)
double applyOperation(T a,T b, char &c) {
    if (c == '+') {
        return a + b;
    }
    else if (c == '-') {
        return a - b;
    }
    else if (c == '*') {
        return a * b;
    }
    else if (c == '/') {
        return a / b;
    }
    return 0;
}

int main() {
    double a,b;
    std::cin >> a >> b;
    char c;
    std::cin >> c;
    std::cout << applyOperation(a,b,c);
    return 0;
}