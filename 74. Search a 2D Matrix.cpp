#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        int r = matrix.size();
		int c = matrix[0].size();
		int low = 0, high = r*c-1;
		int mid, now;
		while (low <= high) {
			mid = (low + high) / 2;
			now = matrix[mid / c][mid % c];
			if (now == target) return true;
			if (now < target) low = mid + 1;
			else high = mid - 1;
		}
		return false;
    }
};

int main() {
	Solution a;
	vector<vector<int>> m {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
	cout << a.searchMatrix(m, 21) << endl;
}
