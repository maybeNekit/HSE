#include <iostream>
#include <map>
#include <set>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::map<int, std::set<std::string>> index;

    for (int i = 0; i < n; ++i) {
        std::string word;
        int page;
        std::cin >> word >> page;
        index[page].insert(word);
    }

    for (const auto& entry : index) {
        std::cout << entry.first;
        for (const auto& word : entry.second) {
            std::cout << " " << word;
        }
        std::cout << '\n';
    }

    return 0;
}
