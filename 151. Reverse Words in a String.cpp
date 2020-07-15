#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int id = 0;
        int start=0, end;
        while (start < s.size()) {
            if (s[start] != ' ') {
                if (id != 0) {
                    s[id++] = ' ';
                }
                end = start;
                while (end < s.size() && s[end] != ' ') {
                    s[id++] = s[end++];
                }
                reverse(s.begin() + id - (end - start), s.begin() + id);
                start = end + 1;
            }
            else {
                start++;
            }
        }
        s.erase(s.begin() + id, s.end());
        return s;
    }
};


int main() {
    auto ans = Solution().reverseWords("  hello world!  ");
    cout << '\"' << ans << '\"' << endl;
    return 0;
}
