#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
		int ans = 1;
		int up = 1;
		int down = 1;
		int peak_height = 1;
		for (int i=1; i < ratings.size(); ++i) {
			if (ratings[i-1] < ratings[i]) {
				up++;
				down = 1;
				peak_height = up;
				ans += up;
			}
			else if (ratings[i-1] == ratings[i]) {
				up = 1;
				down = 1;
				peak_height = 1;
				ans++;
			}
			else {
				up = 1;
				ans += down;
				if (peak_height <= down) ans++;
				down++;
			}
		}
		return ans;
    }
};

int main() {
	Solution a;
	vector<int> v {1, 3, 2, 2, 1};
	cout << a.candy(v) << endl;
}
