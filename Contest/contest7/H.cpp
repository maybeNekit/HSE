#include <iostream>
#include <set>

int main() {
    std::string s;
    std::set<char> set; 
    bool f = true;
    while (std::getline(std::cin, s)) {
        if (s.empty()) {
            break;
        }
        std::set<char> a;
        for (char c : s) {
            a.insert(c);
        }
        if (f) {
            set = a;
            f = false;
        } else {
            std::set<char> b;
            for (char c : set) {
                if (a.count(c)) {
                    b.insert(c);
                }
            }
            set = b;
        }
    }
    for (char c : set) {
        std::cout << c;
    }
    return 0;
}