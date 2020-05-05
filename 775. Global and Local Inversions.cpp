#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        for (int i=0; i < A.size(); ++i) {
            if (abs(A[i]-i) > 1) return false;
        }
        return true;
    }
};

int main() {
    vector<int> v{1,2,0};
    cout << Solution().isIdealPermutation(v) << endl;
    return 0;
}
