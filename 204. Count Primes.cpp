#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> board(n, false);
        int ans = 0;
        for (int i=2; i < n; ++i) {
            if (board[i]) {
                continue;
            }
            ans++;
            for (int j=1; i * j < n; ++j) {
                board[i * j] = true;
                // cout << i * j << endl;
            }
            // cout << endl;
        }
        // cout << endl;
        return ans;
    }
};

int main() {
    for (int i=0; i <= 14; ++i)
        cout << i << ' ' << Solution().countPrimes(i) << endl;
    return 0;
}
