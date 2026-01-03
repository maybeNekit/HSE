#include <string>
#include <algorithm>

std::string common_suffix(const std::string& a, const std::string& b) {
    long long i = a.size() - 1;
    long long j = b.size() - 1;
    while (i >= 0 && j >= 0 && a[i] == b[j]) {
        i--;
        j--;
    }
    return a.substr(i + 1);
}