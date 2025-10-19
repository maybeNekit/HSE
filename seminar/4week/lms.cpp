#include <iostream>
#include <vector>
bool isPositive(int x) {
    return x>0;
}
bool isEven(int x) {
    return x%2==0;
}
std::vector<int> filterArray(
    const std::vector<int>& arr,
    bool (*filter)(int),
    int& resultSize
) {
    std::vector<int> res;
    for (int num : arr) {
        if (filter(num)) {
            res.push_back(num);
        }
    }
    return res;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    int p = 0;
    std::vector<int> pos = filterArray(arr, isPositive, p);
    int e = 0;
    std::vector<int> eve = filterArray(arr, isEven, e);
    for (int x : pos) {
        std::cout << x << " ";
    }
    std::cout << "\n";
    for (int x : eve) {
        std::cout << x << " ";
    }
    return 0;
}