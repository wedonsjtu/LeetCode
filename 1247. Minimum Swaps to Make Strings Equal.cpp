#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minimumSwap(string s1, string s2) {
		if (s1.size() != s2.size()) return -1;
        int yx = 0, xy = 0;
		for (int i=0; i < s1.size(); ++i) {
			if ((s1[i] == 'x') && (s2[i] == 'y')) xy++;
			else if ((s1[i] == 'y') && (s2[i] == 'x')) yx++;
		}
		int ans = xy / 2 + yx / 2;
		xy %= 2;
		yx %= 2;
		if (xy + yx == 2) ans += 2;
		else if (xy + yx == 1) return -1;
		return ans;
    }
};

int main() {
	Solution a;
	cout << a.minimumSwap("xx", "yy") << endl;
	cout << a.minimumSwap("xy", "yx") << endl;
	cout << a.minimumSwap("xx", "yx") << endl;
	cout << a.minimumSwap("xxyyxyxyxx", "xyyxyxxxyx") << endl;
	return 0;
}
