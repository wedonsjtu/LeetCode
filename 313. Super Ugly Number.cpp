#include <iostream>
#include <vector>
using namespace std;

class Solution {  // similar to "264. Ugly Number II"
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int nums[n] = {1};
		int counters[primes.size()] = {0};
		int temp;
		for (int i=1; i < n; ++i) {
			temp = INT32_MAX;
			for (int j=0; j < primes.size(); ++j)
				temp = min(temp, nums[counters[j]] * primes[j]);
			for (int j=0; j < primes.size(); ++j)
				if (temp == nums[counters[j]] * primes[j]) ++counters[j];
			nums[i] = temp;
		}
		return nums[n-1];
    }
};

int main() {
	Solution a;
	vector<int> primes {2, 7, 13, 19};
	for (int i=1; i < 20; ++i) cout << a.nthSuperUglyNumber(i, primes) << ' ';
	cout << endl;
	return 0;
}
