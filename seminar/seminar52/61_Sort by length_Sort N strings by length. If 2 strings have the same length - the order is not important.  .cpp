#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    std::cin.ignore();

    std::vector<std::string> strings(N);

    for (int i = 0; i < N; ++i) {
        std::getline(std::cin, strings[i]);
    }

    std::sort(strings.begin(), strings.end(), [](const std::string& a, const std::string& b) {
        return a.length() < b.length();
    });

    for (const std::string& str : strings) {
        std::cout << str << '\n';
    }

    return 0;
}
