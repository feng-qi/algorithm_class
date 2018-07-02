#include <vector>

int merge_sort(std::vector<int>& v, int l, int r);
int merge(std::vector<int>& v, int l, int m, int r);

int small_sum(std::vector<int>& v) {
    return merge_sort(v, 0, v.size()-1);
}

int merge_sort(std::vector<int>& v, int l, int r) {
    if (l >= r)
        return 0;

    int m = l + ((r - l) >> 1);
    return merge_sort(v, l, m) + merge_sort(v, m+1, r) + merge(v, l, m, r);
}

int merge(std::vector<int>& v, int l, int m, int r) {
    std::vector<int> tmp;
    int i     = l;
    int j     = m+1;
    int count = 0;
    while (i <= m && j <= r) {
        if (v[i] < v[j]) {
            count += v[i] * (r - j + 1);
            tmp.push_back(v[i++]);
        } else
            tmp.push_back(v[j++]);
    }

    while (i <= m) tmp.push_back(v[i++]);
    while (j <= m) tmp.push_back(v[j++]);

    for (int i = 0; i < tmp.size(); ++i)
        v[i+l] = tmp[i];

    return count;
}
