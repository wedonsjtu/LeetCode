#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {  // 视为二叉树
public:
    vector<int> diffWaysToCompute(string input) {
        if (input.empty()) return vector<int>();
		return divideAndConquer(input, 0, input.size()-1);
    }

private:
	vector<int> divideAndConquer(string& input, int start, int end) {
		vector<int> res, left, right;
		for (int i=start; i < end; ++i) {
			if (input[i] == '+' or input[i] == '-' or input[i] == '*') {
				left = divideAndConquer(input, start, i-1);
				right = divideAndConquer(input, i+1, end);
				for (int l: left) {
					for (int r: right) {
						switch (input[i]) {
						case '+':
							res.push_back(l + r);
							break;
						case '-':
							res.push_back(l - r);
							break;
						case '*':
							res.push_back(l * r);
							break;
						}
					}
				}
			}

		}
		if (res.empty()) {  // input里没有运算符
			res.push_back(stoi(input.substr(start, end + 1 - start)));
		}
		return res;
	}
};

int main() {
	Solution a;
	string s("2*3-4*5");
	vector<int> v;
	v = a.diffWaysToCompute(s);
	for (int i: v) cout << i << ' ';
	cout << endl;
	return 0;
}
