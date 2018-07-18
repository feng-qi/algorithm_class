#ifndef QUICKMEDIAN_H
#define QUICKMEDIAN_H

#include <vector>
#include <queue>
#include <iostream>

class QuickMedian {
private:
    std::priority_queue<int> max_heap;
    std::priority_queue<int,std::vector<int>,std::greater<int>> min_heap;

    void adjust_two_heap_size() {
        if (max_heap.size() == min_heap.size() + 2) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        } else if (min_heap.size() == max_heap.size() + 2) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }

    void print_priority_queue(std::priority_queue<int> pq) {
        while (!pq.empty()) {
            std::cout << pq.top() << ' ';
            pq.pop();
        }
        std::cout << '\n';
    }
    void print_priority_queue(std::priority_queue<int,std::vector<int>,std::greater<int>> pq) {
        while (!pq.empty()) {
            std::cout << pq.top() << ' ';
            pq.pop();
        }
        std::cout << '\n';
    }

public:
    void dump_heap() {
        print_priority_queue(max_heap);
        print_priority_queue(min_heap);
    }
    void add_number(int val) {
        if (max_heap.empty()) {
            max_heap.push(val);
            return;
        }
        if (val <= max_heap.top()) {
            max_heap.push(val);
        } else {
            min_heap.push(val);
        }
        adjust_two_heap_size();
    }

    int get_median() {
        if (max_heap.size() + min_heap.size() == 0)
            return 0;
        if (max_heap.size() == min_heap.size())
            return (max_heap.top() + min_heap.top()) / 2;
        else
            return max_heap.size() > min_heap.size() ? max_heap.top() : min_heap.top();
    }
};


#endif /* QUICKMEDIAN_H */
