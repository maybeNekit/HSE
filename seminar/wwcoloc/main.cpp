#include <iostream>

int* first_occurrence(int* arr, int n, int x, int* index) {
    for (int i =0; i<n;i++) {
        if (arr[i]==x) {
            *index = i;
            return &arr[i];
        }
    }
    *index = -1;
    return nullptr;
}

int main() {
    int n;
    std::cin >> n;
    int* a = new int[n];
    for (int i =0; i<n;i++) {
        std::cin >>a[i];
    }
    int x;
    std::cin >> x;
    int idx;
    int* p = first_occurrence(a,n,x,&idx);
    std::cout << idx;
    if (p!=nullptr) {
        std::cout << '\n';
        while (p<a+n) {
            std::cout << *p << " ";
            p++;
        }
    }

    return 0;
}
