#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return intervals;
        sort(intervals.begin(), intervals.end(), comp);
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for (int i=1; i < intervals.size(); ++i) {
            if (intervals[i][0] >= ans[ans.size()-1][0] && 
                intervals[i][0] <= ans[ans.size()-1][1]) {
                if (intervals[i][1] <= ans[ans.size()-1][1]) {
                    continue;
                }
                ans[ans.size()-1][1] = intervals[i][1];
            } else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
    
    static bool comp(const vector<int>& a, const vector<int>& b) {
        if (a[0] != b[0]) return a[0] < b[0];
        return a[1] < b[1];  // why it cannot be equal?
    }
};

int main() {
    vector<vector<int>> v{{1,2},{2,3},{4,5}};
    auto ans = Solution().merge(v);
    for (auto i: ans) cout << i[0] << ' ' << i[1] << " | ";
    cout << endl;
    return 0;
}
