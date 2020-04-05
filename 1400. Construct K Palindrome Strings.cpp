#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool canConstruct(string s, int k) {
        if (k == s.size()) return true;
        if (k > s.size()) return false;
        vector<int> v(26, 0);
        for (char ch: s) {
            v[ch - 'a'] += 1;
        }
        int odd = 0;
        for (auto i: v) {
            if (i % 2) odd++;
        }
        return odd <= k;
    }
};

int main() {
    Solution a;
    cout << a.canConstruct("aaabbbccc", 2) << endl;
    cout << a.canConstruct("aaabbbccc", 3) << endl;
    cout << a.canConstruct("aaabbbccc", 4) << endl;
    return 0;
}
