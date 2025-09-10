#include <iostream>
#include <bitset>
using namespace std;
int main() {
    int a;
    cin >> a;
    const int bits = sizeof(a);
    bitset<bits> b(a);
    cout << b << endl;

    return 0;
}