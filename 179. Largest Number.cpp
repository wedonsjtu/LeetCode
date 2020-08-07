#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if (nums.empty()) return "";
        sort(nums.begin(), nums.end(), comp);
        stringstream ss;
        for (int num: nums) {
            ss << num;
        }
        string s = ss.str();
        if (s[0] == '0') return "0";
        return s;
    }
    
private:
    static string itos(int a) {
        // a is non-negative;
        string ans;
        while (a > 0) {
            ans.push_back('0' + (a % 10));
            a /= 10;
        }
        reverse(ans.begin(), ans.end());
        if (ans.empty()) ans.push_back('0');
        return ans;
    }
    
    static bool comp(const int& a, const int& b) {
        string a_str(itos(a)), b_str(itos(b));
        return b_str + a_str < a_str + b_str;
    }
};

int main() {
    vector<int> nums{3,30,34,5,9};
    auto ans = Solution().largestNumber(nums);
    cout << ans << endl;
    return 0;
}
