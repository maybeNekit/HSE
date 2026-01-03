#include <iostream>
#include <vector>

int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> p(n);
        std::vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            std::cin >> p[i];
            ans[p[i] - 1] = i + 1;
        }

        for (int i = 0; i < n; i++) {
            std::cout << ans[i] << (i == n - 1 ? "" : " ");
        }
        std::cout << std::endl;
    }
    return 0;
}