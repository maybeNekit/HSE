#include <iostream>
#include <set>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }

    std::multiset<int> window;

    for (int i = 0; i < k; i++) {
        window.insert(nums[i]);
    }

    std::cout << *window.begin() << "\n";

    for (int i = k; i < n; i++) {

        auto it = window.find(nums[i - k]);
        window.erase(it);

        window.insert(nums[i]);

        std::cout << *window.begin() << "\n";
    }

    return 0;
}