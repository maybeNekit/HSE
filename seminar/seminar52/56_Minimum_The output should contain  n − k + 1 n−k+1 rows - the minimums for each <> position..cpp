#include <iostream>
#include <set>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> sequence(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> sequence[i];
    }

    std::multiset<int> window;

    for (int i = 0; i < k; ++i) {
        window.insert(sequence[i]);
    }

    std::cout << *window.begin() << '\n';

    for (int i = k; i < n; ++i) {
        window.insert(sequence[i]);
        window.erase(window.find(sequence[i - k]));

        std::cout << *window.begin() << '\n';
    }

    return 0;
}
