#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> m;
        for (int i: barcodes) {
            m[i]++;
        }
        vector<int> ans(barcodes.size(), 0);
        priority_queue<pair<int, int>> pq;
        for (auto it=m.begin(); it != m.end(); ++it) {
            pq.push({it->second, it->first});
        }
        int index = 0;
        int key, value;
        while (!pq.empty()) {
            key = pq.top().second;
            value = pq.top().first;
            pq.pop();
            while (value != 0) {
                if (index >= ans.size()) index = 1;  // All the even positions have been used.
                ans[index] = key;
                --value;
                index += 2;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> v{7,7,7,8,5,7,5,5,5,8};
    auto ans = Solution().rearrangeBarcodes(v);
    for (int i: ans) cout << i << ' ';
    cout << endl;
    return 0;
}
