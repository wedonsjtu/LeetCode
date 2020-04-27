#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() == 0 || s.size() == 0) return "";
        unordered_map<char, int> m;
        for (char ch: t) {
            if (m.find(ch) == m.end()) {
                m[ch] = 1;
            }
            else m[ch]++;
        }
        int l = 0, count = 0, ans_size = s.size() + 1, ans_l = 0;
        for (int r=0; r < s.size(); ++r) {
            if (m.find(s[r]) != m.end()) {
                if (--m[s[r]] >= 0) {
                    ++count;
                }
                while (count == t.size()) {
                    if (r - l + 1 < ans_size) {
                        ans_l = l;
                        ans_size = r - l + 1;
                    }
                    if (m.find(s[l]) != m.end() && ++m[s[l]] > 0) {
                        --count;
                    }
                    ++l;
                }
            }
        }
        if (ans_size > s.size()) {
            return "";
        }
        else return s.substr(ans_l, ans_size);
    }
};

int main() {
    cout << Solution().minWindow("ADOBECODEBANC", "ABC") << endl;
    return 0;
}
