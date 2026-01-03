#include <iostream>
#include <vector>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }

    int lim = 1 << n;
    for (int i = 0; i < lim; i++) {
        std::cout << "[";
        bool f = true;
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) {
                if (!f) std::cout << ",";
                std::cout << s[j];
                f = false;
            }
        }
        std::cout << "]" << std::endl;
    }
    return 0;
}