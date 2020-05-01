#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (s.size() == 0 || p.size() == 0 ||
            p.size() > s.size()) return ans;
        unordered_map<char, int> m;
        int count = 0;
        for (char ch: p) {
            if (m.find(ch) == m.end()) {
                m[ch] = 1;
            }
            else {
                m[ch]++;
            }
            ++count;
        }
        int l = 0;
        for (int r=0; r < s.size(); ++r) {
            m[s[r]]--;
            if (m[s[r]] >= 0) --count;
            while (count == 0) {
                if (r + 1 - l == p.size()) {
                    ans.push_back(l);
                }
                if (m[s[l]] == 0) ++count;
                ++m[s[l]];
                ++l;
            }
        }
        return ans;
    }
};

int main() {
    auto ans = Solution().findAnagrams("abcdede", "de");
    for (int i: ans) cout << i << ' ';
    cout << endl;
    return 0;
}
