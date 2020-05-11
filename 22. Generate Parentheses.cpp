#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(ans, 0, 0, n, "");
        return ans;
    }
    
private:
    void generate(vector<string>& ans, int left_num, int right_num, int pairs, string s) {
        if (s.size() == pairs * 2) {
            ans.push_back(s);
            return;
        }
        if (left_num < pairs) {
            generate(ans, left_num+1, right_num, pairs, s+'(');
        }
        if (left_num > right_num) {
            generate(ans, left_num, right_num+1, pairs, s+')');
        }
    }
};

int main() {
    auto ans = Solution().generateParenthesis(3);
    for (auto i: ans) cout << i << ' ';
    cout << endl;
    return 0;
}
