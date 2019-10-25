#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), cmp);
		int ans = 0;
		int i = 0, j = 0;
		for (; j < pairs.size(); ++j) {
			if (j == 0 || (pairs[i][1] < pairs[j][0])) {
				ans++;
				i = j;
			}
		}
		return ans;
    }
private:
	static bool cmp(vector<int> &a, vector<int> &b) {
		return (a[1] < b[1]);
	}
};
