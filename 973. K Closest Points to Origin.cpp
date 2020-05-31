#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<int, int>, vector<pair<int, int> >, comp> pq;
        pair<int, int> p;
        for (auto& point: points) {
            p.first = point[0];
            p.second = point[1];
            pq.push(p);
            if (pq.size() > K) pq.pop();
        }
        vector<vector<int>> ans;
        vector<int> tmp(2, 0);
        while (!pq.empty()) {
            tmp[0] = pq.top().first;
            tmp[1] = pq.top().second;
            ans.push_back(tmp);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
private:
    class comp {
    public:
        bool operator() (const pair<int, int>& l, const pair<int, int>& r) const {
            return (l.first * l.first + l.second * l.second < r.first * r.first + r.second * r.second);
        }
    };
};

int main() {
    vector<vector<int>> pairs{{3,3},{5,-1},{-2,4}};
    auto ans = Solution().kClosest(pairs, 2);
    for (auto& v: ans) cout << v[0] << ' ' << v[1] << ';' << ' ';
    cout << endl;
    return 0;
}
