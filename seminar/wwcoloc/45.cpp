#include <iostream>
#include <set>

int main() {
    int n;
    std::cin >> n;
    std::set<int> unique_digits;
    while (n > 0) {
        unique_digits.insert(n % 10);
        n/= 10;
    }
    std::cout << unique_digits.size() << '\n';
    return 0;
}
