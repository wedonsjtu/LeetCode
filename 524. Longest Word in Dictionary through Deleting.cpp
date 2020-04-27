#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string ans("");
        for (string sub: d) {
            if (isSubseq(s, sub)) {
                if (sub.size() > ans.size() || 
                    (sub.size() == ans.size() && sub < ans)) {
                    ans = sub;
                }
            }
        }
        return ans;
    }
    
    bool isSubseq(string s, string t) {
        int i = 0, j = 0;
        for (; i < s.size() && j < t.size(); ++i) {
            if (s[i] == t[j]) ++j;
        }
        return j == t.size();
    }
};

int main() {
    // s = "abpcplea", d = ["ale","apple","monkey","plea"]
    vector<string> d{"ale","apple","monkey","plea"};
    cout << Solution().findLongestWord("abpcplea", d) << endl;
    return 0;
}
