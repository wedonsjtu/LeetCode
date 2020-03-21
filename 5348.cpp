#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;
        bool flag = true;
        if (d < 0) d = -d;
        for (auto a1: arr1) {
            flag = true;
            for (auto a2: arr2) {
                if (a1 - a2 <= d && a1 - a2 >= -d) {
                    flag = false;
                    break;
                }
            }
            if (flag) ans++;
        }
        return ans;
    }
};
