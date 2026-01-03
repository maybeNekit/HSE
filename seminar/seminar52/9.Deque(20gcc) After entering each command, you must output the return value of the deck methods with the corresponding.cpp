#include <iostream>
#include <vector>
#include <string>

class Deque {
    std::vector<int> val;
public:
    void pushb(int a) {
        val.push_back(a);
    }
    void pushf(int a) {
        val.insert(val.begin(), a);
    }
    int popb() {
        if (val.empty()) return 0;
        int res = val.back();
        val.pop_back();
        return res;
    }
    int popf() {
        if (val.empty()) return 0;
        int res = val.front();
        val.erase(val.begin());
        return res;
    }
    int back() {
        if (val.empty()) return 0;
        return val.back();
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
    Deque deq;
    for (int i = 0; i < n; ++i) {
        std::string command;
        std::cin >> command;
        if (command == "push_back") {
            int x;
            std::cin >> x;
            deq.pushb(x);
            std::cout << "added\n";
        } else if (command == "push_front") {
            int x;
            std::cin >> x;
            deq.pushf(x);
            std::cout << "added\n";
        } else if (command == "pop_back") {
            std::cout << deq.popb() << '\n';
        } else if (command == "pop_front") {
            std::cout << deq.popf() << '\n';
        } else if (command == "back") {
            std::cout << deq.back() << '\n';
        } else if (command == "front") {
            std::cout << deq.front() << '\n';
        } else if (command == "size") {
            std::cout << deq.size() << '\n';
        }
    }
    return 0;
}
