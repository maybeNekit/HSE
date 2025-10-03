#include <iostream>
using namespace std;

int main() {
    char a;
    cin >> a;
    if ((int(a) >= 97 && int(a) <= 122) or (int(a) >= 65 && int(a) <= 90)){
        cout << "correct";
    } else {
        cout << "incorrect";
    }
    return 0;
}