#include <iostream>
#include <set>

int main() {
    std::string input;
    std::getline(std::cin, input);

    std::set<char> char_set;
    for (char c : input) {
        if (char_set.count(c) > 0) {
            std::cout << "NO" << '\n';
            return 0;
        }
        char_set.insert(c);
    }

    std::cout << "YES" << '\n';
    return 0;
}
