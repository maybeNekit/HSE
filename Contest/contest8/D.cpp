#include <algorithm>
#include <map>
#include <string>
#include <vector>

struct Star {
    std::string name;
    uint64_t age;
};
std::string FindStar(const std::vector<Star>& s) {
    std::map<std::string, uint64_t> m;
    for (const auto& i : s) {
        m[i.name] = std::max(m[i.name], i.age);
    }
    std::vector<uint64_t> v;
    for (const auto& p : m) {
        v.push_back(p.second);
    }
    std::sort(v.begin(), v.end());
    size_t k = v.size() / 2;
    uint64_t t = v[k];
    for (const auto& p : m) {
        if (p.second == t) return p.first;
    }
    return "";
}