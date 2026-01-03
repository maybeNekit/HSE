#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> prog(n);

    for (int i = 0; i < n; ++i) {
        int mask = 0;
        for (int j = 0; j < m; ++j) {
            int bit;
            std::cin >> bit;
            if (bit == 1) {
                mask |= (1 << j);
            }
        }
        prog[i] = mask;
    }
    int ALL = (1 << m) - 1;
    int ans = 0;
    for (int subset = 1; subset < (1 << n); ++subset) {
        int mask = 0;
        for (int i = 0; i < n; ++i) {
            if (subset & (1 << i)) {
                mask |= prog[i];
            }
        }
        if (mask == ALL) {
            ++ans;
        }
    }
    std::cout << ans << "\n";

    return 0;
}