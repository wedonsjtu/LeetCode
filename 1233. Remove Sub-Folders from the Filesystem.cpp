#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        // if (folder.empty()) return ans;
        sort(folder.begin(), folder.end());
        string parent;
        int i = 0;
        while (i < folder.size()) {
            ans.push_back(folder[i]);
            parent = folder[i] + '/';
            ++i;
            while (i < folder.size() && 
                   folder[i].substr(0, parent.size()) == parent) {
                ++i;
            }
        }
        return ans;
    }
};

int main() {
    vector<string> v{"/a","/a/b","/c/d","/c/d/e","/c/f"};
    auto ans = Solution().removeSubfolders(v);
    for (string& s: ans) cout << s << ' ';
    cout << endl;
    return 0;
}
