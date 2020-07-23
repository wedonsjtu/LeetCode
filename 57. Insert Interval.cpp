#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // 二分搜索找左区间点和右区间点位置
        // 合并之间的区间
        int left_index = binarySearch(intervals, newInterval[0], true);
        int right_index = binarySearch(intervals, newInterval[1], false);
        if (right_index == -1) {
            vector<vector<int>> ans;
            ans.push_back(newInterval);
            ans.insert(ans.end(), intervals.begin(), intervals.end());
            return ans;
        }
        vector<vector<int>> ans(intervals.begin(), intervals.begin() + left_index);
        // cout << left_index << ' ' << right_index << endl;
        if (left_index == intervals.size()) {
            ans.push_back(newInterval);
            return ans;
        }
        vector<int> midInterval{0, 0};
        // cout << left_index << ' ' << right_index << endl;
        midInterval[0] = min(newInterval[0], intervals[left_index][0]);
        midInterval[1] = max(newInterval[1], intervals[right_index][1]);
        // cout << midInterval[0] << ' ' << midInterval[1] << endl;
        ans.push_back(std::move(midInterval));
        ans.insert(ans.end(), intervals.begin() + right_index + 1, intervals.end());
        return ans;
    }
    
private:
    int binarySearch(vector<vector<int>>& intervals, int target, bool beginOrEnd=true) {
        int begin = 0, end = intervals.size() - 1;
        int mid;
        while (begin <= end) {
            mid = begin + (end - begin) / 2;
            if (intervals[mid][0] <= target && target <= intervals[mid][1]) {
                return mid;
            }
            if (intervals[mid][0] > target) {
                end = mid - 1;
            }
            else {
                begin = mid + 1;
            }
        }
        return (beginOrEnd?begin:end);
    }
};

int main() {
    vector<vector<int>> intervals{{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int> newInterval{4, 8};
    vector<vector<int>> ans = Solution().insert(intervals, newInterval);
    for (vector<int>& v: ans) {
        cout << '[' << v[0] << ',' << v[1] << ']' << ' ';
    }
    cout << endl;
    return 0;
}
