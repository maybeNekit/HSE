#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

int main() {
    std::string a, b;
    std::getline(std::cin, a);
    std::getline(std::cin, b);

    for (char &c : a) c = std::tolower(static_cast<unsigned char>(c));
    for (char &c : b) c = std::tolower(static_cast<unsigned char>(c));

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    if (a == b) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}