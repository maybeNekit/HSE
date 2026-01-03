#include <iostream>
#include <string>

std::string extractDigits(const std::string& str) {
    std::string result = "";
    for (char ch : str) {
        if (isdigit(ch)) {
            result += ch;
        }
    }
    return result;
}

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::cout << extractDigits(input) << std::endl;
    return 0;
}
