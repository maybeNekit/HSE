#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> pi(n), pi_inv(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> pi[i];
        pi[i]--;
    }

    for (int i = 0; i < n; ++i) {
        pi_inv[pi[i]] = i;
    }

    for (int i = 0; i < n; ++i) {
        std::cout << pi_inv[i] + 1 << " ";
    }
    std::cout << std::endl;

    return 0;
}
