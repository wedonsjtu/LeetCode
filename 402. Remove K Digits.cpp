#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        // int len = num.length();
		string result;
		if (k == num.length()) {
			result.push_back('0');
			return result;
		}
		int min_index = 0, beginning_index = 0;
		int i = 0;
		while (true) {
			for (i=beginning_index; i<beginning_index+k+1; ++i) {
				if (num[i] < num[min_index]) min_index = i;
			}
			k -= (min_index - beginning_index);
			result.push_back(num[min_index]);
			beginning_index = min_index + 1;
			min_index = beginning_index;
			if (k == 0) {
				if (beginning_index < num.length()) result += num.substr(beginning_index);
				while (result[0] == '0' and result.length() > 1) result =  result.substr(1);
				return result;
			}
		}
    }
};

int main() {
	Solution a;
	cout << a.removeKdigits("10200", 1) << endl;
	cout << a.removeKdigits("2000000435345654613", 12) << endl;
	cout << a.removeKdigits("10", 2) << endl;
	cout << a.removeKdigits("76786512145765143232425219", 23) << endl;
}
