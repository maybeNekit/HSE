#include <iostream>
#include <string>
#include <map>

int main() {
    std::string l;
    std::map<char, int> m;
    while (std::getline(std::cin, l)) {
        if (l.empty()) {
            break;
        }
        for (char c : l) {
            if (c != ' ') {
                m[c]++;
            }
        }
    }
    int h = 0;
    for (auto p : m) {
        if (p.second > h) {
            h = p.second;
        }
    }
    for (int r = h; r > 0; r--) {
        std::string o;
        for (auto p : m) {
            if (p.second >= r) {
                o += '#';
            } else {
                o += ' ';
            }
        }
        std::cout << o << '\n';
    }
    for (auto p : m) {
        std::cout << p.first;
    }
    std::cout << '\n';
    return 0;
}