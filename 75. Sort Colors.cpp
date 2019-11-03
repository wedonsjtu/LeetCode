#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0, j=0, k;
		for (int ii=0; ii < nums.size(); ++ii) {
			k = nums[ii];
			nums[ii] = 2;
			if (k < 2) {
				nums[j++] = 1;
			}
			if (k == 0) {
				nums[i++] = 0;
			}
		}
    }
};

int main() {
	Solution a;
	vector<int> nums = {0,1,1,0,2,1,0,2,1,2,0,0,1};
	a.sortColors(nums);
	for (int i: nums) cout << i << ' ';
	cout << endl;
	return 0;
}
