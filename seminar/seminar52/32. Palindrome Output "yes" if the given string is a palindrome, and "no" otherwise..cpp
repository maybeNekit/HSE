#include <iostream>
#include <string>

bool is_palindrome(const std::string& s) {
    int i = 0;
    int j = (int)s.size() - 1;
    while (i < j) {
        if (s[i] == ' ') {
            i++;
            continue;
        }
        if (s[j] == ' ') {
            j--;
            continue;
        }
        if (s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main() {
    std::string s;
    std::getline(std::cin, s);
    if (is_palindrome(s)) {
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }
    return 0;
}