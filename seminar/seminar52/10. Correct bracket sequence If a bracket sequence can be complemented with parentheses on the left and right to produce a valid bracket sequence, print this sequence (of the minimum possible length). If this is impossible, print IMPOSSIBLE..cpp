#include <iostream>
#include <string>
#include <vector>

char get_opp(char c) {
    if (c == ')') return '(';
    if (c == ']') return '[';
    if (c == '}') return '{';
    if (c == '(') return ')';
    if (c == '[') return ']';
    return '}';
}

int main() {
    std::string s;
    std::cin >> s;

    std::vector<char> st;
    std::string pre = "";

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push_back(c);
        } else {
            if (st.empty()) {
                pre += get_opp(c);
            } else {
                char top = st.back();
                if ((top == '(' && c == ')') ||
                    (top == '[' && c == ']') ||
                    (top == '{' && c == '}')) {
                    st.pop_back();
                    } else {
                        std::cout << "IMPOSSIBLE\n";
                        return 0;
                    }
            }
        }
    }

    std::cout << pre << s;
    while (!st.empty()) {
        std::cout << get_opp(st.back());
        st.pop_back();
    }
    std::cout << '\n';

    return 0;
}