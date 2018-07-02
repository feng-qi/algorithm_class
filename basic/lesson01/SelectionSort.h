#include <algorithm>
#include <vector>

void selection_sort(std::vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
        int imin = i;
        for (int j = i; j < v.size(); ++j)
            imin = v[j] < v[imin] ? j : imin;
        std::swap(v[imin], v[i]);
    }
}
