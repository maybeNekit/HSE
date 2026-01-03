#include <iostream>
#include <unordered_set>

int main() {
    int num;
    std::unordered_set<int> seen;

    while (std::cin >> num) {
        if (seen.count(num) == 0) {
            std::cout << "NO" << std::endl;
            seen.insert(num);
        } else {
            std::cout << "YES" << std::endl;
        }

        if (std::cin.peek() == '\n') {
            break;
        }
    }

    return 0;
}
