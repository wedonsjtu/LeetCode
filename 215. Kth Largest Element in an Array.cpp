#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, less<int>> pq(nums.begin(), nums.end());
		int ans = 0;
		for(; k != 0; --k) {
			ans = pq.top();
			pq.pop();
		}
		return ans;
    }
};

int main() {
	Solution a;
	vector<int> v {3,2,3,1,2,4,5,5,6};
	cout << a.findKthLargest(v, 4) << endl;
}
