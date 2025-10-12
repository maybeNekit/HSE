#include <iostream>
#include <functional>

template<typename F, typename G>
auto compose(F f, G g) {
    return [f, g](auto x) {
        return f(g(x));
    };
}

int addOne(int x) {
    return x + 1;
}

int mulTwo(int x) {
    return x * 2;
}

int main() {

    auto h = compose(mulTwo, addOne);

    std::cout << h(5) << std::endl;


    auto toStr = [](int x) { return std::to_string(x); };
    auto quote = [](const std::string& s) { return "\"" + s + "\""; };
    auto addQuotes = compose(quote, toStr);

    std::cout << addQuotes(42) << std::endl; // "42"

    return 0;
}