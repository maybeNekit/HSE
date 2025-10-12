#include <iostream>
int compose(int (*f)(int), int (*g)(int), int x) {
    return f(g(x));
}
int f1(int x) {
    return x + 1;
}
int f2(int x) {
    return x * 2;
}
int main() {
    int a = 5;

    int result = compose(f1, f2, a);
    std::cout << result << std::endl;
    return 0;
}