#include <iostream>
using namespace std;

int main() {
    int a,n,b,res;
    cin >> a >> n;
    b = (1 << n)-1;
    res = a & b;
    cout << res << endl;
    return 0;
}