#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 1;
        int curr = 1;
        for (auto num: s) {
            if (s.find(num-1) == s.end()) {
                curr = 1;
                while (s.find(num+1) != s.end()) {
                    ++curr;
                    ++num;
                }
                if (curr > longest) {
                    longest = curr;
                }
            }
        }
        return longest;
    }
};

int main() {
    vector<int> nums{100, 4, 200, 1, 3, 2};
    auto ans = Solution().longestConsecutive(nums);
    cout << ans << endl;
    return 0;
}
