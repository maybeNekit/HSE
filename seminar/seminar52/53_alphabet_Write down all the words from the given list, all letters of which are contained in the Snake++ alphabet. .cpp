#include <iostream>
#include <set>
#include <string>

int main() {
    std::string alphabet;
    std::cin >> alphabet;

    int N;
    std::cin >> N;

    std::set<char> snakeAlphabet(alphabet.begin(), alphabet.end());

    for (int i = 0; i < N; ++i) {
        std::string word;
        std::cin >> word;

        bool valid = true;
        for (char c : word) {
            if (snakeAlphabet.find(c) == snakeAlphabet.end()) {
                valid = false;
                break;
            }
        }

        if (valid) {
            std::cout << word << '\n';
        }
    }

    return 0;
}
