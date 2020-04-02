#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q;
    MyStack():q() {
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        long long s = q.size();
        while (s > 1) {
            q.push(q.front());
            q.pop();
            --s;
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int ans = q.front();
        q.pop();
        return ans;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main() {
    MyStack obj;
    obj.push(1);
    obj.push(2);
    obj.push(3);
    cout << obj.top() << endl;
    cout << obj.pop() << endl;
    cout << obj.pop() << endl;
    obj.push(4);
    cout << obj.pop() << endl;
    cout << obj.pop() << endl;
    return 0;
}
