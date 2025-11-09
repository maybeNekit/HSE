#include <iostream>
#include <vector>
#include <set>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }
    std::multiset<int> m;
    for (int i = 0; i < k; ++i) {
        m.insert(v[i]);
    }
    std::cout << *m.begin() << '\n';
    
    for (int i = k; i < n; ++i) {
        m.erase(m.find(v[i - k]));
        m.insert(v[i]);
        std::cout << *m.begin() << '\n';
    }
    return 0;
}