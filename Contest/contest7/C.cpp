#include <iostream>
#include <map>
#include <vector>
int main() {
    int n;
    std::cin >> n;
    std::map<std::string,std::vector<int>> m;
    for (int i=0; i<n;++i) {
        int k;
        std::cin >> k;
        for (int j=0;j<k;j++) {
            std::string s;
            int a;
            std::cin >> s >> a;
            m.emplace(s, std::vector<int>(n, 0));
            m[s][i] = a;
        }
    }

    for (const auto& pair : m) {
        std::cout << pair.first <<'\t';
        for (const auto& p : pair.second) {
            std::cout << p << '\t';
        }
        std::cout <<'\n';
    }
    return 0;
}