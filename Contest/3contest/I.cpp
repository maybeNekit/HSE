#include <iostream>

int main() {
    int n;
    int f = 0;
    int s = 0;
    int k = 0;

    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;

        if (x == 0) {
            ++k;
        }
        f = (f ^ x) & ~s;
        s = (s ^ x) & ~f;
    }

    int X = 0;
    int cnt = 0;

    if (f != 0) {
        X = f;
        cnt = 1;
    } else if (s != 0) {
        X = s;
        cnt = 2;
    } else {
        cnt = k % 3;
        X = 0;
        if (cnt == 0) {
            cnt = 0;
        }
    }

    std::cout << X << ' ' << cnt << '\n';
    return 0;
}