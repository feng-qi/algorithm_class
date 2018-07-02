#include <algorithm>
#include <vector>

static void merge_sort_impl(std::vector<int>& v, int l, int r);
static void merge(std::vector<int>& v, int l, int m, int r);

void merge_sort(std::vector<int>& v) {
    merge_sort_impl(v, 0, v.size()-1);
}

static void merge_sort_impl(std::vector<int>& v, int l, int r) {
    if (l >= r) return;

    int m = l + ((r - l) >> 1);
    merge_sort_impl(v, l, m);
    merge_sort_impl(v, m+1, r);
    merge(v, l, m, r);
}

static void merge(std::vector<int>& v, int l, int m, int r) {
    int i1 = l;
    int i2 = m+1;
    std::vector<int> tmp;

    while (i1 <= m && i2 <= r)
        tmp.push_back(v[i1] < v[i2] ? v[i1++] : v[i2++]);
    while (i1 <= m) tmp.push_back(v[i1++]);
    while (i2 <= r) tmp.push_back(v[i2++]);
    // for (int i = 0; i < tmp.size(); ++i)
    //     v[l+i] = tmp[i];
    std::copy(tmp.begin(), tmp.end(), std::next(v.begin(), l));
}
