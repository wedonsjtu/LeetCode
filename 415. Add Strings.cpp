#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1 == "0") return num2;
        if (num2 == "0") return num1;
        string ans;
        int plus = 0, tmp;
        int p1 = num1.size() - 1;
        int p2 = num2.size() - 1;
        while (p1 >= 0 && p2 >= 0) {
            tmp = (int)(num1[p1] - '0') + (int)(num2[p2] - '0') + plus;
            plus = tmp / 10;
            ans.push_back('0' + (tmp % 10));
            --p1;
            --p2;
        }
        while (p1 >= 0) {
            tmp = (int)(num1[p1] - '0') + plus;
            plus = tmp / 10;
            ans.push_back('0' + (tmp % 10));
            --p1;
        }
        while (p2 >= 0) {
            tmp = (int)(num2[p2] - '0') + plus;
            plus = tmp / 10;
            ans.push_back('0' + (tmp % 10));
            --p2;
        }
        if (plus > 0) {
            ans.push_back('0' + plus);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    auto ans = Solution().addStrings("9999999999999999999999999999999999", "1");
    cout << ans << endl;
    return 0;
}
