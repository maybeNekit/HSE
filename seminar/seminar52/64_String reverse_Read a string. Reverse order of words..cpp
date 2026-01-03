#include <iostream>
#include <vector>

int main() {
    std::string input;
    std::getline(std::cin, input);

    std::vector<std::string> words;
    std::string word;

    for (char c : input) {
        if (c == ' ') {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        } else {
            word += c;
        }
    }

    if (!word.empty()) {
        words.push_back(word);
    }

    for (int i = words.size() - 1; i >= 0; --i) {
        std::cout << words[i];
        if (i != 0) {
            std::cout << ' ';
        }
    }
    std::cout << '\n';

    return 0;
}
