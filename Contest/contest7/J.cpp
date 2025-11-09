#include <iostream>
#include <string>
#include <unordered_set>

int main() {
    std::string l;
    std::unordered_set<int> s;
    while (std::getline(std::cin, l)) {
        if (l.empty()) break;
        std::string nu = "";
        for (int i = 0; i <= l.length(); i++) {
            if (i == l.length() || l[i] == ' ') {
                if (!nu.empty()) {
                    int num = 0;
                    for (char c : nu) {
                        num = num * 10 + (c - '0');
                    }
                    if (s.count(num)) {
                        std::cout << "YES\n";
                    } else {
                        std::cout << "NO\n";
                        s.insert(num);
                    }
                    nu = "";
                }
            } else {
                nu += l[i];
            }
        }
    }
    return 0;
}