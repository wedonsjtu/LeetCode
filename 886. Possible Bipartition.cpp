#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(N, vector<int>());
        for (auto& dislike: dislikes) {
            graph[dislike[0]-1].push_back(dislike[1]-1);
            graph[dislike[1]-1].push_back(dislike[0]-1);
        }
        vector<bool> isVisited(N, false);
        vector<bool> color(N, false);
        stack<int> s;
        int now;
        for (int i=0; i < N; ++i) {
            if (isVisited[i]) continue;
            isVisited[i] = true;
            color[i] = true;
            s.push(i);
            while (!s.empty()) {
                now = s.top();
                s.pop();
                for (int j: graph[now]) {
                    if (!isVisited[j]) {
                        isVisited[j] = true;
                        color[j] = !color[now];
                        s.push(j);
                    } else if (color[j] == color[now]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    vector<vector<int>> m{{1,2},{1,3},{2,4}};
    auto ans = Solution().possibleBipartition(4, m);
    cout << boolalpha << ans << endl;
    return 0;
}
