#include <iostream>
#include <vector>
using namespace std;

class CustomStack {
public:
    vector<int> s;
    int top_index;
    int max_size;

    CustomStack(int maxSize) {
        s = vector<int>(maxSize, 0);
        top_index = -1;
        max_size = maxSize;
    }
    
    void push(int x) {
        if (top_index + 1 >= max_size) {
            return;
        }
        s[++top_index] = x;
    }
    
    int pop() {
        if (top_index == -1) return -1;
        return s[top_index--];
    }
    
    void increment(int k, int val) {
        for (int i=0; i < k && i <= top_index; ++i) {
            s[i] += val;
        }
    }
};