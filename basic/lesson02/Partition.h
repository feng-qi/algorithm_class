#include <vector>
#include <utility>

void partition2(std::vector<int>& v) {
    int le = 0;
    int cur = 0;
    while (cur < v.size()) {
        if (v[cur] <= v.back()) {
            std::swap(v[le++], v[cur++]);
        } else {
            ++cur;
        }
    }
}

void partition3(std::vector<int>& v) {
    int lt = -1;
    int gt = v.size()-1;
    int cur = 0;

    while (cur < gt) {
        if (v[cur] < v.back()) {
            std::swap(v[cur++], v[++lt]);
        } else if (v[cur] > v.back()) {
            std::swap(v[cur], v[--gt]);
        } else {
            ++cur;
        }
    }
    std::swap(v[gt], v.back());
}
