#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
		int last_is_up = 1;
		int last_is_down = 1;
		for (int i=1; i < nums.size(); ++i) {
			if (nums[i] > nums[i-1]) last_is_up = last_is_down + 1;
			else if (nums[i] < nums[i-1]) last_is_down = last_is_up + 1;
		}
		return max(last_is_up, last_is_down);
    }
};

int main() {
	Solution a;
	vector<int> n {1,7,4,9,2,5};
	cout << a.wiggleMaxLength(n) << endl;
}
