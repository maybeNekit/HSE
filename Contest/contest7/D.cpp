#include <iostream>
#include <set>
#include <string>

int main() {
    std::string line;
    std::set<std::string> d;

    while (std::getline(std::cin, line)) {
        if (line.empty()) {
            break;
        }
        d.insert("/");
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == '/') {
                std::string dir = line.substr(0, i + 1);
                d.insert(dir);
            }
        }
    }

    for (const auto& dir : d) {
        std::cout << dir << std::endl;
    }
    return 0;
}