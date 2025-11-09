#include <iostream>
#include <vector>
#include <string>
#include <set>

int main() {
    int m;  
    std::cin >> m;
    std::vector<std::set<char>> w(m);
    for (int i = 0; i < m; ++i) {
        std::string test;
        std::cin >> test;

        for (char c : test) {
            w[i].insert(c);
        }
    }
    int n;
    std::cin >> n;
    std::vector<std::string> num(n);
    std::vector<int> k(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> num[i];
    }
    for (int i = 0; i < n; ++i) {
        std::set<char> ch;

        for (char c : num[i]) {
            ch.insert(c);
        }
        for (const auto& wi : w) {
            bool fl = true;

            for (char c : wi) {
                if (ch.find(c) == ch.end()) {
                    fl = false;
                    break;
                }
            }
            if (fl) {
                k[i]++;
            }
        }
    }
    int match = 0;
    for (int count : k) {
        if (count > match) {
            match = count;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (k[i] == match) {
            std::cout << num[i] << '\n';
        }
    }
    return 0;
}