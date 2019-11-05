#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end(), less<int>());
		int cloest_value = nums[0] + nums[1] + nums[2];
		int tmp_value;
		int i, j, k;
		for (i=0; i < nums.size()-2; ++i) {
			j = i + 1;
			k = nums.size() - 1;
			while (j < k) {
				tmp_value = nums[i] + nums[j] + nums[k];
				if (abs(tmp_value - target) < abs(cloest_value - target)) cloest_value = tmp_value;
				if (tmp_value < target) j++;
				else if (tmp_value > target) k--;
				else return tmp_value;
			}
		}
		return cloest_value;
    }
};

int main() {
	Solution a;
	vector<int> v = {-1, 2, 1, -4};
	cout << a.threeSumClosest(v,-4) << endl;
	return 0;
}
