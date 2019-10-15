#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>, less<int>> pq(stones.begin(), stones.end());
		int x, y;
		while (pq.size() > 1) {
			y = pq.top();
			pq.pop();
			x = pq.top();
			pq.pop();
			if (x == y) continue;
			pq.push(y - x);
		}
		return pq.size()?pq.top():0;
    }
};

int main() {
	Solution a;
	vector<int> v = {2, 7, 4, 1, 8, 1};
	cout << a.lastStoneWeight(v) << endl;
	return 0;
}
