#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        long long a = 0, b = 0;
        for (string s: tokens) {
            if (s == "+") {
                b = st.top();
                st.pop();
                a = st.top();
                st.pop();
                st.push(a + b);
            }
            else if (s == "-") {
                b = st.top();
                st.pop();
                a = st.top();
                st.pop();
                st.push(a - b);
            }
            else if (s == "*") {
                b = st.top();
                st.pop();
                a = st.top();
                st.pop();
                st.push(a * b);
            }
            else if (s == "/") {
                b = st.top();
                st.pop();
                a = st.top();
                st.pop();
                st.push(a / b);
            }
            else {
                st.push((long long)stoi(s));
            }
        }
        if (st.empty()) return 0;
        return st.top();
    }
};
