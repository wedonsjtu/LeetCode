#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class myComparison
{
public:
     bool operator() (const pair<long long, long long>&a, const pair<long long, long long>&b) const {
        if (a.first != b.first) return a.first >= b.first;
        return a.second >= b.second;
    }
};

class Solution {
public:
    long long compute(long long x) {
        long long ans = 0;
        while (x > 1) {
            if (x % 2) x = 3 * x + 1;
            else x = x / 2;
            ans++;
        }
        return ans;
    }

    int getKth(int lo, int hi, int k) {
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, myComparison> q;
        long long i;
        for (int x = lo; x <= hi; ++x) {
            i = compute(x);
            // cout << i << ' ' << x << endl;
            q.push(pair<long long, long long>(i, x));
        }
        for (int j = 0; j < k-1; ++j) {
            // cout << q.top().second << endl;
            q.pop();
        }
        return q.top().second;
    }
};

int main() {
    Solution a;
    cout << a.getKth(12,15,2) << endl;
    return 0;
}
