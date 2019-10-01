#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ans = 0;
		int total_gas = 0;
		int total_cost = 0;
		int now_gas = 0;
		for (int i=0; i < gas.size(); ++i) {
			total_gas += gas[i];
			total_cost += cost[i];
			now_gas += gas[i] - cost[i];
			if (now_gas < 0) {
				now_gas = 0;
				ans = i + 1;
			}
		}
		return (total_gas < total_cost)?-1:ans;
    }
};

int main() {
	Solution a;
	vector<int> gas {1, 2, 3, 4, 5};
	vector<int> cost {3, 4, 5, 1, 2};
	cout << a.canCompleteCircuit(gas, cost) << endl;
	vector<int> gas1 {2, 3, 4};
	vector<int> cost1 {3, 4, 3};
	cout << a.canCompleteCircuit(gas1, cost1) << endl;
}
