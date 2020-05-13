#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int kInversePairs(int n, int k) {
        const int M = 1000000007;
        int* last = new int[k+1]();
        int* now = new int[k+1]();
        int* tmp;
        last[0] = 1;
        now[0] = 1;
        for (int i=1; i <= n; ++i) {
            for (int j=1; j <= k; ++j) {
                if (j < i) {
                    now[j] = (now[j-1] + last[j]) % M;
                }
                else {
                    now[j] = (now[j-1] + (last[j] + M - last[j-i]) % M) % M;
                }
            }
            tmp = last;
            last = now;
            now = tmp;
        }
        int ans = last[k];
        delete[] last;
        delete[] now;
        return ans;
    }
    
    // int kInversePairs(int n, int k) {
    //     int* last = new int[k+1]();
    //     int* now = new int[k+1]();
    //     int* tmp;
    //     last[0] = 1;
    //     now[0] = 1;
    //     for (int i=1; i <= n; ++i) {
    //         for (int j=1; j <= k; ++j) {
    //             now[j] = 0;
    //             for (int p = 0; p <= min(j, i-1); ++p) {
    //                 now[j] = (now[j] + last[j-p]) % 1000000007;
    //             }
    //         }
    //         tmp = last;
    //         last = now;
    //         now = tmp;
    //     }
    //     int ans = last[k];
    //     delete[] last;
    //     delete[] now;
    //     return ans;
    // }
};

int main() {
    auto ans = Solution().kInversePairs(1000, 1000);
    cout << ans << endl;
    return 0;
}
