#include <algorithm>            // std::swap
#include <vector>

void insertion_sort(std::vector<int>& v) {
    for (int i = 1; i < v.size(); ++i) {
        for (int j = i; j > 0 && v[j] < v[j-1]; --j)
            std::swap(v[j], v[j-1]);
    }
}

void insertion_sort2(std::vector<int>& v) {
    for (int i = 1; i < v.size(); ++i) {
        int j   = i-1;
        int val = v[i];
        for (; j >= 0 && v[j] > val; --j)
            v[j+1] = v[j];

        if (j < 0)
            v[0] = val;
        else
            v[j+1] = val;
    }
}
