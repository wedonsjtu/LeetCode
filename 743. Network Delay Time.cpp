#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<int>> g(N, vector<int>(N, -1));
        for (auto& time: times) {
            if (g[time[0]-1][time[1]-1] == -1) {
                g[time[0]-1][time[1]-1] = time[2];
            }
            else {
                g[time[0]-1][time[1]-1] = min(g[time[0]-1][time[1]-1], time[2]);
            }
        }
        vector<int> distance(N, INT_MAX);
        vector<bool> isVisited(N, false);
        distance[K-1] = 0;
        int currNode, currDis = INT_MAX;
        for (int i=0; i < N; ++i) {
            currDis = INT_MAX;
            for (int j=0; j < N; ++j) {
                if (!isVisited[j] && currDis >= distance[j]) {
                    currNode = j;
                    currDis = distance[j];
                }
            }
            if (currDis == INT_MAX) return -1;
            isVisited[currNode] = true;
            for (int j=0; j < N; ++j) {
                if (!isVisited[j] && g[currNode][j] >= 0) {
                    distance[j] = min(distance[j], distance[currNode] + g[currNode][j]);
                }
            }
        }
        // for (int i: distance) cout << i << ' ';
        // cout << endl;
        int ans = 0;
        for (int i=0; i < N; ++i) {
            if (distance[i] >= ans) {
                ans = distance[i];
            }
        }
        if (ans == INT_MAX) return -1;
        return ans;
    }
};

int main() {
    vector<vector<int>> times{{2,1,1},{2,3,1},{3,4,1}};
    auto ans = Solution().networkDelayTime(times, 4, 2);
    cout << ans << endl;
    return 0;
}
