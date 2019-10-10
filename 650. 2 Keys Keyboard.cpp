#include <iostream>
using namespace std;

class Solution {
public:
    int minSteps(int n) {
		int result = 0;
        for (int i=2; i <= n; ++i) {
			while (n % i == 0) {
				result += i;
				n /= i;
			}
		}
		return result;
    }
};

int main() {
	Solution a;
	for (int i=1; i < 10; ++i) cout << a.minSteps(i) << endl;
}
