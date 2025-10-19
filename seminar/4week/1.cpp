#include <iostream>
#include <vector>

bool isPositive(int x) {
    return x > 0;
}
bool isEven(int x) {
    return x % 2 == 0;
}
std::vector<int> filterArray(
    const std::vector<int>& arr,
    bool (*filter)(int),
    int& resultSize
) {
    std::vector<int> result;
    for (int num : arr) {
        if (filter(num)) {
            result.push_back(num);
        }
    }
    resultSize = result.size();
    return result;
}
int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    int positiveSize = 0;
    std::vector<int> positives = filterArray(arr, isPositive, positiveSize);
    int evenSize = 0;
    std::vector<int> evens = filterArray(arr, isEven, evenSize);
    for (int x : positives) std::cout << x << " ";
    std::cout << "\n";
    for (int x : evens) std::cout << x << " ";
    std::cout << "\n";
    return 0;
}