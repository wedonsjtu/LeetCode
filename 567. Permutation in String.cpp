#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() == 0 || s1.size() > s2.size()) return false;
        if (s1.size() == 0) return true;
        unordered_map<char, int> m;
        int count = 0;
        for (char ch: s1) {
            m[ch]++;
            ++count;
        }
        int l = 0;
        for (int r=0; r < s2.size(); ++r) {
            m[s2[r]]--;
            if (m[s2[r]] >= 0) --count;
            while (count == 0) {
                if (r + 1 - l == s1.size()) {
                    return true;
                }
                if (m[s2[l]] == 0) ++count;
                ++m[s2[l]];
                ++l;
            }
        }
        return false;
    }
};

int main() {
    cout << Solution().checkInclusion("ab", "eidbaooo") << endl;
    return 0;
}
