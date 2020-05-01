#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans = t[t.size()-1];
        for (int i=0; i < s.size(); ++i) {
            ans ^= (s[i] ^ t[i]);
        }
        return ans;
    }
};

int main() {
    cout << Solution().findTheDifference("qwerty", "ytraewq") << endl;
    return 0;
}
