#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countArrangement(int N) {
        vector<bool> isVisited(N, false);
        int ans=0;
        backtracking(isVisited, N, 1, ans);
        return ans;
    }

private:
    void backtracking(vector<bool>& isVisited, const int N, int now, int& ans) {
        if (now > N) {
            ++ans;
            return;
        }
        for (int i=1; i <= N; ++i) {
            if (!isVisited[i-1] && (now % i == 0 || i % now == 0)) {
                isVisited[i-1] = true;
                backtracking(isVisited, N, now+1, ans);
                isVisited[i-1] = false;
            }
        }
    }
};

int main() {
    Solution sol;
    for (int i=1; i <= 15; ++i) {
        cout << i << '\t' << sol.countArrangement(i) << endl;
    }
    return 0;
}
