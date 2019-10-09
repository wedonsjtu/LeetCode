#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0) return false;
        int r = 0;
		int c = matrix[0].size() - 1;
		while (r < matrix.size() && c >= 0) {
			if (matrix[r][c] == target) return true;
			if (matrix[r][c] < target) ++r;
			else --c;
		}
		return false;
    }
};

int main() {
	Solution a;
	vector<vector<int>> m {{1, 4, 7, 11, 15},{2, 5, 8, 12, 19},{3, 6, 9, 16, 22},{10, 13, 14, 17, 24},{18, 21, 23, 26, 30}};
	cout << a.searchMatrix(m, 1) << endl;
}
