#include <iostream>
#include <string>
#include <set>
int main() {
    std::string s;
    std::cin >> s;
    std::set<char> set(s.begin(),s.end());
    int n;
    std::cin >> n;
    for (int i=0; i<n;++i) {
        int f = 1;
        std::string a;
        std::cin>> a;
        for (char j: a) {
            if (set.find(j)==set.end()) {
                f=0;
                break;
            }
        }
        if (f) {
            std::cout << a << '\n';
        }
    }

    return 0;
}