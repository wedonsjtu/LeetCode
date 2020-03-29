#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans = 0;
        for (int i=1; i < rating.size() - 1; ++i) {
            pair<int, int> less, greater;
            for (int j=0; j < rating.size(); ++j) {
                if (rating[j] < rating[i]) {
                    if (j < i) ++less.first;
                    else ++less.second;
                }
                if (rating[j] > rating[i]) {
                    if (j < i) ++greater.first;
                    else ++greater.second;
                }
            }
            ans += less.first * greater.second + less.second * greater.first;
        }
        return ans;
    }
    
    // int numTeams(vector<int>& rating) {
    //     if (rating.size() < 3) return 0;
    //     int n = rating.size();
    //     int ans = 0;
    //     bool flag = true; // greater
    //     for (int i=0; i < n; ++i) {
    //         for (int j=i+1; j < n; ++j) {
    //             flag = (rating[i] > rating[j]);
    //             for (int k=j+1; k < n; ++k) {
    //                 if (flag) {
    //                     if (rating[k] > rating[j]) continue;
    //                     ++ans;
    //                 }
    //                 if (!flag) {
    //                     if (rating[k] < rating[j]) continue;
    //                     ++ans;
    //                 }
    //             }
    //         }
    //     }
    //     return ans;
    // }
};

int main() {
    Solution a;
    vector<int> v{1,2,3,4};
    cout << a.numTeams(v) << endl;
    return 0;
}
