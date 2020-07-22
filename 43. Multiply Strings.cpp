#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string ans("0");
        string strChar;
        for (int i=0; i < num2.size(); ++i) {
            strChar = multiplyChar(num1, num2[num2.size() - 1 - i]);
            if (strChar[0] != '0') {
                for (int j=0; j < i; ++j) {
                    strChar.push_back('0');
                }
            }
            ans = addStrings(ans, strChar);
        }
        return ans;
    }
    
private:
    string multiplyChar(string num1, char ch) {
        if (num1 == "0" || ch == '0') return "0";
        if (ch == '1') return num1;
        string ans;
        int plus = 0;
        int tmp;
        for (int i=num1.size() - 1; i >= 0; --i) {
            tmp = (int)(num1[i] - '0') * (int)(ch - '0') + plus;
            plus = tmp / 10;
            ans.push_back('0' + (tmp % 10));
        }
        if (plus != 0) ans.push_back('0' + plus);
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
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
    auto ans = Solution().multiply("99999999999999999",
                                   "99999999999999999");
    cout << ans << endl;
    return 0;
}
