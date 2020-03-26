#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {return a[1] < b[1];});
        int ans = 0;
        int now = intervals[0][1];
        for (int i=1; i < intervals.size(); ++i) {
            if (intervals[i][0] < now) {
                ++ans;
                continue;
            }
            else {
                now = intervals[i][1];
            }
        }
        return ans;
    }
};

int main() {
    Solution a;
    vector<int> v{1, 2};
    vector<vector<int>> m = {v, v, v};
    cout << a.eraseOverlapIntervals(m) << endl;
    return 0;
}
