template <typename It, typename Pred>
bool AnyOf(It first, It last, Pred f) {
    for (; first != last; ++first) {
        if (f(*first)) {
            return true;
        }
    }
    return false;
}