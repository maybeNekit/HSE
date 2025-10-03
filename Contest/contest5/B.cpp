#include <iostream>
#include <string>
#include <algorithm>

int pol(std::string &s) {
    std::string t = s;
    std::reverse(t.begin(), t.end());
    if (t == s) {
        return 1;
    }
    return 0;
}

int main() {
    std::string s;
    std::getline(std::cin, s);
    s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
    if (pol(s)) {
        std::cout << "yes";
    } else {
        std::cout << "no";
    }
    return 0;
}