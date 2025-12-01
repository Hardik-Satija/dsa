#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
    vector<int> h;
public:
    void push(int x) {
        h.push_back(x);
        int i = h.size() - 1;
        while (i > 0) {
            int p = (i - 1) / 2;
            if (h[p] < h[i]) {
                swap(h[p], h[i]);
                i = p;
            } else break;
        }
    }
    bool empty() const {
        return h.empty();
    }
    int top() const {
        if (h.empty()) throw runtime_error("empty");
        return h[0];
    }
    void pop() {
        if (h.empty()) return;
        h[0] = h.back();
        h.pop_back();
        int n = h.size();
        int i = 0;
        while (true) {
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            int largest = i;
            if (l < n && h[l] > h[largest]) largest = l;
            if (r < n && h[r] > h[largest]) largest = r;
            if (largest != i) {
                swap(h[i], h[largest]);
                i = largest;
            } else break;
        }
    }
};

int main() {
    MaxHeap pq;
    pq.push(5);
    pq.push(2);
    pq.push(8);
    pq.push(10);
    int x = pq.top();
    pq.pop();
    return 0;
}
