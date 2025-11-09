#include <iostream>
#include <vector>
#include <string>
#include <stack>

int main() {
    std::string s;
    std::string res = "yes";
    std::cin >> s;
    std::vector<std::string> v = {"()", "[]", "{}"};
    std::stack<char> st;
    for (int i = 0; i < s.length(); ++i) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        }
        else {
            if (st.empty()) {
                res = "no";
                break;
            }
            char top = st.top();
            st.pop();
            std::string pair = std::string(1, top) + std::string(1, c);
            bool found = false;

            for (const auto& pa : v) {
                if (pair == pa) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                res = "no";
                break;
            }
        }
    }
    if (!st.empty()) {
        res = "no";
    }
    std::cout << res;
    return 0;
}