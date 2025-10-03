#include <iostream>
using namespace std;
int main() {
    int a, b, i;
    cin >> a>> i;
    b =  a >> i;
    if (b&1) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}