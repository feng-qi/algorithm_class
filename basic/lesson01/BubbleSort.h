#include <vector>
#include <utility>              // std::swap

void bubble_sort(std::vector<int>& vals) {
    for (int i = vals.size() - 1; i > 0; --i) {
        for (int j = 0; j < i; ++j) {
            if (vals[j] > vals[j+1])
                std::swap(vals[j], vals[j+1]);
        }
    }
}
