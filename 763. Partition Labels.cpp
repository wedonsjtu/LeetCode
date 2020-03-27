#include <iostream>
#include <vector>
#include <array>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        array<int, 26> last_index{0};
        for (int i=0; i < S.size(); ++i) {
            last_index[S[i] - 'a'] = i;
        }
        int now_max = 0, first_index = 0;
        vector<int> ans;
        for (int i=0; i < S.size(); ++i) {
            now_max = max(now_max, last_index[S[i]-'a']);
            if (now_max == i) {
                ans.push_back(now_max - first_index + 1);
                first_index = now_max + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution a;
    auto v = a.partitionLabels("qwertyqwertyuiopasdfghjklzxcvbnm");
    for (auto i: v) cout << i << ' ';
    cout << endl;
    return 0;
}
