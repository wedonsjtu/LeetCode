#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
		int five = 0, ten = 0;  // we don't need record 20
        for (int i=0; i < bills.size(); ++i) {
			switch (bills[i]) {
			case 5:
				++five;
				break;
			case 10:
				if (five == 0) return false;
				++ten;
				--five;
				break;
			case 20:
				if (ten == 0) {
					if (five < 3) return false;
					five -= 3;
					break;
				}
				--ten;
				if (five == 0) return false;
				--five;
				break;
			}
		}
		return true;
    }
};

int main() {
	Solution a;
	vector<int> v {5, 5, 10, 10, 20};
	cout << a.lemonadeChange(v) << endl;
}
