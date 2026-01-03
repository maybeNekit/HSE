#include <iostream>
#include <map>

int main() {
    std::string input;
    std::getline(std::cin, input);

    std::map<char, int> freq;

    for (char c : input) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            if (c >= 'a' && c <= 'z') {
                c -= 'a' - 'A';
            }
            freq[c]++;
        }
    }

    for (const auto& p : freq) {
        std::cout << p.first << ' ' << p.second << '\n';
    }

    return 0;
}
