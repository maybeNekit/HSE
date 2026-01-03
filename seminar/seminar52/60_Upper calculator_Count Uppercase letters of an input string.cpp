#include <iostream>

int main() {
    std::string input;
    std::getline(std::cin, input);

    int count = 0;
    for (char c : input) {
        if (c >= 'A' && c <= 'Z') {
            count++;
        }
    }

    std::cout << count << '\n';

    return 0;
}
