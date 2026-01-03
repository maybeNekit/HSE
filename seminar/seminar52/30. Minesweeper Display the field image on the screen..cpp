#include <iostream>
#include <cctype>

void count_stats(std::istream& in, int& letters, int& words, int& lines) {
    letters = 0;
    words = 0;
    lines = 0;
    char c;
    char last = 0;
    bool in_word = false;
    bool empty = true;

    while (in.get(c)) {
        empty = false;
        last = c;

        if (std::isalpha(static_cast<unsigned char>(c))) {
            letters++;
            if (!in_word) {
                words++;
                in_word = true;
            }
        } else {
            in_word = false;
        }

        if (c == '\n') {
            lines++;
        }
    }

    if (!empty && last != '\n') {
        lines++;
    }
}

int main() {
    int l, w, n;
    count_stats(std::cin, l, w, n);

    std::cout << "Input file contains:\n";
    std::cout << l << " letters \n";
    std::cout << w << " words \n";
    std::cout << n << " lines \n";

    return 0;
}