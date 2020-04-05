#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numSteps(string s) {
        int times = 0;
        while (s != "1") {
            if (s[s.size()-1] == '0') {
                s = s.substr(0, s.size()-1);
            }
            else {
                int i = s.size()-1;
                while (i >= 0) {
                    if (s[i] == '0') break;
                    --i;
                }
                if (i < 0) {
                    s = "1" + s;
                    i = 1;
                }
                else {
                    s[i] = '1';
                    ++i;
                }
                while (i < s.size()) {
                    s[i] = '0';
                    ++i;
                }
            }
            ++times;
        }
        return times;
    }
};

int main() {
    Solution a;
    cout << a.numSteps("1101") << endl;
    cout << a.numSteps("10") << endl;
    cout << a.numSteps("1") << endl;
    return 0;
}
