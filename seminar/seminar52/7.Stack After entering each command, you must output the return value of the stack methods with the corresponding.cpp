#include <iostream>
#include <vector>
#include <string>

class Stack {
    std::vector<int> v;
public:
    void push(int a) {
        v.push_back(a);
    }
    int pop() {
        int r = v.back();
        v.pop_back();
        return r;
    }
    int top() {
        return v.back();
    }
    int size() {
        return v.size();
    }
};

int main() {
    int n;
    std::cin >> n;
    Stack s;
    for (int i = 0; i < n; i++) {
        std::string cmd;
        std::cin >> cmd;
        if (cmd == "push") {
            int x;
            std::cin >> x;
            s.push(x);
            std::cout << "added\n";
        } else if (cmd == "pop") {
            std::cout << s.pop() << '\n';
        } else if (cmd == "top") {
            std::cout << s.top() << '\n';
        } else if (cmd == "size") {
            std::cout << s.size() << '\n';
        }
    }
    return 0;
}