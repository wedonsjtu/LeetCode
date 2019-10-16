#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
		int start = 0, end = A.size()-1;
        vector<int> ans(A.size(), 0);
		for (int i: A) {
			if (i % 2) ans[end--] = i;
			else ans[start++] = i;
		}
		return ans;
    }
};

int main() {
	Solution a;
	vector<int> v = {1,3,6,2,5,7,2,12,5,2};
	v = a.sortArrayByParity(v);
	for (int i: v) cout << i << ' ';
	cout << endl;
	return 0;
}
