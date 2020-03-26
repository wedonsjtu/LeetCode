#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int num = 0;
        int i = points.size() - 1, shot_pos;
        while (i >= 0) {
            ++num;
            shot_pos = points[i][0];
            while (i >= 1 && points[i-1][1] >= shot_pos) --i;
            --i;
        }
        return num;
    }
};
