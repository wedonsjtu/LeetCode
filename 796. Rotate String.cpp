#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool rotateString(string A, string B) {
        return ((A.size() == B.size()) && ((A + A).find(B) != string::npos));
    }
};

int main() {
    auto ans = Solution().rotateString("abcde", "cdeab");
    cout << boolalpha << ans << endl;
    return 0;
}
