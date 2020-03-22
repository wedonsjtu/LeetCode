#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        int times = 0;
        vector<int> divs;
        unordered_map<int, int> yes;
        unordered_set<int> no;
        for (int num: nums) {
            if (no.find(num) != no.end()) continue;
            if (yes.find(num) != yes.end()) {
                ans += yes[num];
                continue;
            }
            if (num < 4) continue;
            divs.clear();
            divs.push_back(1);
            divs.push_back(num);
            times = 0;
            int n = num;
            int max_1 = num / 2+1;
            for (int i=2; i<max_1;++i) {
                // cout << n << ' ' << i <<endl;
                if (n % i == 0) {
                    times++;
                    if (times > 2) {no.insert(num); break;}
                    divs.push_back(i);
                    if (n / i != i) times++, divs.push_back(n / i);
                    if (times > 2) {no.insert(num); break;}
                    max_1 = min(max_1, max(i, n / i));
                }
            }
            if (times == 2) {
                int sum1 = 0;
                for (auto i: divs) sum1 += i;
                yes[num] = sum1;
                ans += sum1;
            }
            else {
                no.insert(num);
            }
        }
        return ans;
    }
};

int main() {
    Solution a;
    vector<int> v{21,12,13,4,53,2,3,5,6,5,34,232,12,4345,2343,43225,424};
    vector<int> vi{21,21,21,21};
    cout << a.sumFourDivisors(v) << endl;
    cout << a.sumFourDivisors(vi) << endl;
    return 0;
}
