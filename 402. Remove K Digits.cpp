#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        for (char ch: num) {
            while (!ans.empty() && ans.back() > ch && k > 0) {
                ans.pop_back();
                --k;
            }
            if (!ans.empty() || ch != '0') {
                ans.push_back(ch);
            }
        }
        while (!ans.empty() && k > 0) {
            ans.pop_back();
            --k;
        }
        if (ans.empty()) return "0";
        return ans;
    }
};

int main() {
	Solution a;
	cout << a.removeKdigits("10200", 1) << endl;
	cout << a.removeKdigits("2000000435345654613", 12) << endl;
	cout << a.removeKdigits("10", 2) << endl;
	cout << a.removeKdigits("76786512145765143232425219", 23) << endl;
	cout << a.removeKdigits("112", 1) << endl;
}
