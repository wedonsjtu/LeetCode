#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> v;
        if (k == 0) return v;
        unordered_map<int, int> m;
        for (int num: nums) {
            m[num]++;
            if (m[num] == 1) v.push_back(num);
        }
        int low = 0, high = v.size()-1;
        int mid;
        while (low <= high) {
            mid = quick_divide(m, v, low, high);
            if (mid + 1 == k) {
                return vector<int>(v.begin(), v.begin() + k);
            }
            if (mid + 1 > k) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return vector<int>();
    }
    
private:
    int quick_divide(unordered_map<int, int>& m, vector<int>& v, int low, int high) {
        int tmp = v[low];
        while (low != high) {
            while (low < high && m[tmp] > m[v[high]]) --high;
            if (low < high) {
                v[low] = v[high];
                ++low;
            }
            while (low < high && m[tmp] < m[v[low]]) ++low;
            if (low < high) {
                v[high] = v[low];
                --high;
            }
        }
        v[low] = tmp;
        return low;
    }
};

int main() {
    vector<int> v{1,2,2,1,1,3};
    int k = 2;
    auto ans = Solution().topKFrequent(v, k);
    for (int i: ans) cout << i << ' ';
    cout << endl;
    return 0;
}
