#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        stack<int> s;
        for (int num: nums2) {
            while (!s.empty() && s.top() < num) {
                m[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }
        vector<int> ans;
        for (int num: nums1) {
            if (m.find(num) == m.end()) {
                ans.push_back(-1);
            } else {
                ans.push_back(m[num]);
            }
        }
        return ans;
    }
};

int main() {
    vector<int> v1{0,3,5,6};
    vector<int> v2{3,0,6,1,5};
    auto ans = Solution().nextGreaterElement(v1, v2);
    for (int i: ans) cout << i << ' ';
    cout << endl;
    return 0;
}
