#include <iostream>
#include <string>
#include <vector>
class Queue {
    std::vector<int> val;
public:
    void push(int a) {
        val.push_back(a);
    }
    int pop() {
        if (val.empty()) return 0;
        int popit = val.front();
        val.erase(val.begin());
        return popit;
    }
    int front() {
        if (val.empty()) return 0;
        return val.front();
    }
    int size() {
        return static_cast<int>(val.size());
    }
};
int main() {
    int n;
    std::cin >> n;
    Queue q;
    for (int i = 0; i < n; ++i) {
        std::string command;
        std::cin >> command;
        if (command == "push") {
            int x;
            std::cin >> x;
            q.push(x);
            std::cout << "added\n";
        } else if (command == "pop") {
            std::cout << q.pop() << '\n';
        } else if (command == "front") {
            std::cout << q.front() << "\n";
        } else if (command == "size") {
            std::cout << q.size() << "\n";
        }
    }
    return 0;
}
