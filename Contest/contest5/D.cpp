#include <iostream>

void rev(int arr[], int a, int i) {
    arr[a - 1] = i + 1;
}

int main() {
    int n;
    std::cin >> n;
    int arr[20000];
    for (int i = 0; i < n; i++) {
        arr[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        rev(arr, a, i);
    }
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    return 0;
}