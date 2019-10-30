#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res(numCourses, 0);
		if (prerequisites.size() == 0) {
			for (int j=0; j < numCourses; ++j) res[j] = j;
		}
        vector<vector<int>> edges(numCourses, vector<int>());
		int* in_degree = new int[numCourses]();
		int i;
		for (i=0; i < prerequisites.size(); ++i) {
			if (prerequisites[i][0] == prerequisites[i][1]) return vector<int>();
			edges[prerequisites[i][1]].push_back(prerequisites[i][0]);
			in_degree[prerequisites[i][0]]++;
		}
		// for (int j=0; j < numCourses; ++j) cout << in_degree[j] << ' ';
		// cout << endl;
		queue<int> q;
		int now_index = 0;  // res's current index
		for (i=0; i < numCourses; ++i) {
			if (in_degree[i] == 0) q.push(i);
		}
		int current;
		while (!q.empty()) {
			current = q.front();
			// cout << current << endl;
			q.pop();
			res[now_index++] = current;
			if (now_index == numCourses) return res;
			for (int j: edges[current]) {
				// cout << j << endl;
				if (--in_degree[j] == 0) q.push(j);
			}
		}
		return vector<int>();
    }
};

int main() {
	Solution a;
	vector<vector<int>> v = {vector<int>({1,0}), vector<int>({0,1})};
	vector<int> result = a.findOrder(2, v);
	for (int i: result) cout << i << ' ';
	cout << endl;
	return 0;
}
