#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> count(N+1, 0);
        for (auto& tru: trust) {
            count[tru[0]]--;
            count[tru[1]]++;
        }
        for (int i=1; i <= N; ++i) {
            if (count[i] == N-1) return i;
        }
        return -1;
    }
};

int main() {
    vector<vector<int>> m{{1,3},{2,3},{3,1}};
    auto ans = Solution().findJudge(3, m);
    cout << ans << endl;
    return 0;
}
