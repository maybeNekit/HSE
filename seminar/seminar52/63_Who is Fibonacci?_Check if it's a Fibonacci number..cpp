#include <iostream>

bool isFibonacci(int n) {
    if (n < 0) return false;
    int a = 0, b = 1;
    while (b < n) {
        int temp = b;
        b = a + b;
        a = temp;
    }
    return (b == n || n == 0);
}

int main() {
    int n;
    std::cin >> n;

    if (isFibonacci(n)) {
        std::cout << "YES" << '\n';
    } else {
        std::cout << "NO" << '\n';
    }

    return 0;
}
