template <typename Iter>
Iter Unique(Iter first, Iter last) {
    if (first == last) return first;

    Iter result = first;
    ++first;

    while (first != last) {
        if (*first != *result) {
            ++result;
            *result = *first;
        }
        ++first;
    }

    return ++result;
}
