#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> a_plus_b;
        int ans = 0;
        for (int a: A) {
            for (int b: B) {
                ++a_plus_b[a+b];
            }
        }
        for (int c: C) {
            for (int d: D) {
                auto it = a_plus_b.find(-c-d);
                if (it != a_plus_b.end()) {
                    ans += it->second;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> a{1,-1};
    cout << s.fourSumCount(a,a,a,a) << endl;
    return 0;
}
