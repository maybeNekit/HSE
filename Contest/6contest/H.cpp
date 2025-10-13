#include <iostream>
#include <vector>
#include <string>
#include <limits>

int main() {
    int a, b;
    std::cin >> a >> b;
    std::string s;
    std::cin >> s;
    std::vector<int> n(b);
    for (int i = 0; i < b; i++) {
        std::cin >> n[i];
    }
    long long res = std::numeric_limits<long long>::min();
    std::vector<std::string> ans;
    for (int i = 1; i < a; i++) {
        std::string pr;
        std::cin >> pr;
        std::vector<int> n2(b);
        for (int j = 0; j < b; j++) {
            std::cin >> n2[j];
        }
        long long mult = 0;
        for (int j = 0; j < b; j++) {
            mult += (n[j]) * n2[j];
        }
        if (mult > res) {
            res = mult;
            ans.clear();
            ans.push_back(pr);
        }
        else if (mult == res) {
            ans.push_back(pr);
        }
    }
    for (const auto &w : ans) {
        std::cout << w << "\n";
    }
    return 0;
}