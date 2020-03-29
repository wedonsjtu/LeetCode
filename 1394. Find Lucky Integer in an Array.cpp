#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> m;
        int ans = -1;
        bool flag = false;
        for (auto i: arr) {
            if (m.find(i) == m.end()) m[i] = 1;
            else m[i] += 1;
        }
        for (auto it=m.begin(); it != m.end(); ++it) {
            if (it->first == it->second) {
                if (!flag) {
                    flag = true;
                    ans = it->first;
                }
                else {
                    ans = max(ans, it->first);
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution a;
    vector<int> v{1,2,3,4};
    cout << a.findLucky(v) << endl;
    return 0;
}
