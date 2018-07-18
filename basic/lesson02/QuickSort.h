#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>
#include <tuple>
#include <iostream>
#include <utility>

void partition2(std::vector<int>& v, int l, int r) {
    if (l >= r) return;
    int le = l-1;
    int cur = l;
    while (cur <= r) {
        if (v[cur] <= v[r]) {
            std::swap(v[cur++], v[++le]);
        } else {
            ++cur;
        }
    }
    partition2(v, l, le-1);
    partition2(v, le+1, r);
}

void quick_sort2(std::vector<int>& v) {
    partition2(v, 0, v.size()-1);
}

std::tuple<int, int> partition3(std::vector<int>& v, int l, int r) {
    int lt = l-1;
    int gt = r;
    int cur = l;
    while (cur < gt) {
        if (v[cur] < v[r])
            std::swap(v[cur++], v[++lt]);
        else if (v[cur] > v[r])
            std::swap(v[cur], v[--gt]);
        else
            ++cur;
    }
    std::swap(v[gt], v[r]);
    return std::make_tuple(lt+1, gt);
}

void quick_sort3(std::vector<int>& v, int l, int r) {
    if (l >= r) return;
    std::tuple<int,int> eq = partition3(v, l, r);
    quick_sort3(v, l, std::get<0>(eq)-1);
    quick_sort3(v, std::get<1>(eq)+1, r);
}

void quick_sort3(std::vector<int>& v) {
    quick_sort3(v, 0, v.size()-1);
}

void partition3_(std::vector<int>& v, int l, int r) {
    if (l >= r) return;
    int lt = l-1;
    int gt = r;
    int cur = l;
    while (cur < gt) {
        if (v[cur] < v[r])
            std::swap(v[cur++], v[++lt]);
        else if (v[cur] > v[r])
            std::swap(v[cur], v[--gt]);
        else
            ++cur;
    }
    std::swap(v[gt], v[r]);
    partition3_(v, l, lt);
    partition3_(v, gt+1, r);
}

void quick_sort3_(std::vector<int>& v) {
    partition3_(v, 0, v.size()-1);
}

#endif /* QUICKSORT_H */
