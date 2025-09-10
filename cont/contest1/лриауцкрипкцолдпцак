#include <iostream>
using namespace std;

int main() {
    int a = 109;
    int v, t, r;
    cin >> v >> t;
    r = v*t;
    if (r >= 0) {
        if (r <109) {
            cout<< r;
        } else {
            cout << r%a;
        }
    } else {
        if (r >= -108) {
            cout << r + a;
        } else {
            int b = a - (-r%a);
            if (b == 109) {
                cout << 0;
            } else {
                cout << b;
            }
        }
    }
    return 0;
}