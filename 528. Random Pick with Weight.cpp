#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

class Solution {
private:
    vector<int> s;
public:
    Solution(vector<int>& w) {
        for (int i: w) {
            if (s.empty()) {
                s.push_back(i);
            } else {
                s.push_back(s.back() + i);
            }
        }
    }
    
    int pickIndex() {
        return upper_bound(s.begin(), s.end(), rand() % s.back()) - s.begin();
    }
};

int main() {
    srand((unsigned)time(NULL));
    vector<int> w{1,3};
    Solution sol(w);
    for (int i=0; i < 10; ++i) cout << sol.pickIndex() << ' ';
    cout << endl;
    return 0;
}
