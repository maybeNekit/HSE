#include <vector>

template <typename T>
void delete_zeroes(std::vector<T>& a) {
    a.erase(
        std::remove(a.begin(), a.end(), T(0)),
        a.end()
    );
}