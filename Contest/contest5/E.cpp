#include <iostream>

void f(int arr[][100], int a, int b, int &ma, int &mai, int &maj) {
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            if (arr[i][j] > ma || mai == -1) {
                ma = arr[i][j];
                mai = i;
                maj = j;
            }
        }
    }
}

int main() {
    int a, b;
    std::cin >> a >> b;
    int arr[100][100];
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            std::cin >> arr[i][j];
        }
    }
    int ma = 0, mai = -1, maj = -1;
    f(arr, a, b, ma, mai, maj);
    std::cout << mai << " " << maj;

    return 0;
}