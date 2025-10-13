#include <vector>

template <typename T>
void process(const std::vector<T>& v) {
    std::vector<T> res;
    for (const T& i : v) {
        if (i > 0)
            res.push_back(i);
    }
    print_results(res.begin(), res.end());
}