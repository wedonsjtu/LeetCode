#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int length = citations.size();
        vector<int> count(length + 1, 0);
        for (int c: citations) {
            if (c >= length) {
                count[length]++;
            } else {
                count[c]++;
            }
        }
        int sum1 = 0;
        for (int i=length; i > 0; --i) {
            sum1 += count[i];
            if (sum1 >= i) return i;
        }
        return 0;
    }
};

int main() {
    vector<int> v{3,0,6,1,5};
    cout << Solution().hIndex(v) << endl;
    return 0;
}
