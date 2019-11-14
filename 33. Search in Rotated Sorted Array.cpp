#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
		if (nums.size() == 0) return -1;
		int begin = 0, end = nums.size() - 1, mid;
		while (begin < end) {
			mid = (begin + end) / 2;
			if (nums[mid] > nums[end]) {
				if (target > nums[mid] || target <= nums[end]) begin = mid + 1;
				else end = mid;
			}
			else {
				if (target > nums[mid] && target <= nums[end]) begin = mid + 1;
				else end = mid;
			}
		}
		if (begin == end && target != nums[begin]) return -1;
		return begin;
    }
};

int main() {
	Solution a;
	vector<int> v = {4,5,6,7,0,1,2};
	cout << a.search(v, 5) << endl;
	return 0;
}
