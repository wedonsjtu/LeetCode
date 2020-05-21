#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> v(1 << 5, -1);
        v[0] = 0;
        int ans = 0;
        int status = 0;
        for (int i=0; i < s.size(); ++i) {
            switch (s[i]) {
                case 'a':
                    status ^= (1 << 0);
                    break;
                case 'e':
                    status ^= (1 << 1);
                    break;
                case 'i':
                    status ^= (1 << 2);
                    break;
                case 'o':
                    status ^= (1 << 3);
                    break;
                case 'u':
                    status ^= (1 << 4);
                    break;
            }
            if (v[status] == -1) {
                v[status] = i + 1;
            }
            else {
                ans = max(ans, i + 1 - v[status]);
            }
        }
        return ans;
    }
};

int main() {
    auto ans = Solution().findTheLongestSubstring("leetcodeisgreat");
    cout << ans << endl;
    return 0;
}
