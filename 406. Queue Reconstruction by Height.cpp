#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		auto sort_pair = [](const vector<int> &a, const vector<int> &b) {
			return (a[0] > b[0]) || (a[0] == b[0] && a[1] < b[1]);
		};
        sort(people.begin(), people.end(), sort_pair);
		vector<vector<int>> res;
		for (vector<int> person: people) {
			res.insert(res.begin() + person[1], person);
		}
		return res;
    }
};

int main() {
	Solution a;
	vector<vector<int>> p = {vector<int>({7, 0}), vector<int>({4, 4}), vector<int>({7, 1}), vector<int>({5, 0}), vector<int>({6, 1}), vector<int>({5, 2})};
	p = a.reconstructQueue(p);
	for (auto i: p) cout << i[0] << ' ' << i[1] << endl;
	return 0;
}
