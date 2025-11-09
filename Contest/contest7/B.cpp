#include <iostream>
#include <map>
#include <set>
int main() {
    int n;
    std::cin >> n;
    std::map<int, std::set<std::string>> m;
    for (int i=0; i<n; ++i) {
        std::string s;
        int a;
        std::cin >> s >> a;
        m[a].insert(s);
    }
    for (auto& [k, v] : m) {
        std::cout << k;
        for (const auto& w : v) {
            std::cout << w << " ";
        }
        std::cout << '\n';
    }
    return 0;
}