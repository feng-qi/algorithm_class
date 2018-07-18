#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <vector>
#include <utility>
#include <iostream>

void heap_insert(std::vector<int>& v, int i) {
    std::cout << "i: " << i << '\n'
              << "divide: " << ((i-1) / 2) << '\n'
              << "shiftR: " << ((i-1) >> 1) << "\n------------\n";
    while (v[i] > v[(i-1) / 2]) {
        std::swap(v[i], v[(i-1) / 2]);
        i = (i-1) / 2;
    }
}

void heapify(std::vector<int>& v, int i, int size) {
    int l = i * 2 + 1;
    while (l < size) {
        int r = l + 1;
        int greatest = r < size && v[r] > v[l] ? r : l;
        greatest = v[greatest] > v[i] ? greatest : i;
        if (greatest == i)
            break;
        std::swap(v[greatest], v[i]);
        i = greatest;
        l = i * 2 + 1;
    }
}

void heap_sort(std::vector<int>& v) {
    if (v.size() < 2)
        return;
    for (int i = 0; i < v.size(); ++i) {
        heap_insert(v, i);
    }
    int size = v.size();
    std::swap(v[0], v[--size]);
    while (size > 0) {
        heapify(v, 0, size);
        std::swap(v[0], v[--size]);
    }
}

#endif /* HEAPSORT_H */
