#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		if (prerequisites.size() == 0) return true;
        vector<vector<int>> edges(numCourses, vector<int>());
		int* in_degree = new int[numCourses]();
		int i;
		for (i=0; i < prerequisites.size(); ++i) {
			if (prerequisites[i][0] == prerequisites[i][1]) return false;
			edges[prerequisites[i][1]].push_back(prerequisites[i][0]);
			in_degree[prerequisites[i][0]]++;
		}
		bool has_changed, exist_node;
		while (true) {
			has_changed = false;
			exist_node = false;
			for (i=0; i < numCourses; ++i) {
				if (in_degree[i] == 0) {
					for (int j: edges[i]) {
						in_degree[j]--;
					}
					in_degree[i] = -1;
					has_changed = true;
				}
				else if (in_degree[i] != -1) exist_node = true;
			}
			if (has_changed) continue;
			// cout << in_degree[0] << in_degree[1] << endl;
			delete[] in_degree;
			return !exist_node;
		}
    }
};

int main() {
	Solution a;
	vector<vector<int>> v = {vector<int>({1,0}),vector<int>({0,1})};
	cout << a.canFinish(2, v) << endl;
	return 0;
}
