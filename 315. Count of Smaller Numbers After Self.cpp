#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        vector<pair<int, int>> num_index;
        for (int i=0; i < nums.size(); ++i) {
            num_index.push_back({nums[i], i});
        }
        mergeSort(num_index, 0, num_index.size()-1, ans);
        return ans;
    }

private:
    void mergeSort(vector<pair<int, int>>& nums, int begin, int end, vector<int>& ans) {
        if (begin >= end) return;
        int mid = begin + (end - begin) / 2;
        mergeSort(nums, begin, mid, ans);
        mergeSort(nums, mid+1, end, ans);
        for (int i=begin, j=mid+1; i <= mid; ++i) {
            while (j <= end && nums[i].first > nums[j].first) ++j;
            ans[nums[i].second] += j - (mid + 1);
        }
        merge(nums, begin, mid, end);
    }
    
    void merge(vector<pair<int, int>>& A, int start, int mid, int end) {
        // https://leetcode.com/problems/reverse-pairs/solution/
        int n1 = (mid - start + 1);
        int n2 = (end - mid);
        // vector<int> L(n1, 0), R(n2, 0);
        int L[n1], R[n2];
        int Li[n1], Ri[n2];
        for (int i = 0; i < n1; i++) {
            L[i] = A[start + i].first;
            Li[i] = A[start + i].second;
        }
        for (int j = 0; j < n2; j++) {
            R[j] = A[mid + 1 + j].first;
            Ri[j] = A[mid + 1 + j].second;
        }
        int i = 0, j = 0;
        for (int k = start; k <= end; k++) {
            if (j >= n2 || (i < n1 && L[i] <= R[j])) {
                A[k].first = L[i];
                A[k].second = Li[i];
                ++i;
            } else {
                A[k].first = R[j];
                A[k].second = Ri[j];
                ++j;
            }
        }
    }
};

int main() {
    vector<int> v{5,2,6,1};
    auto ans = Solution().countSmaller(v);
    for (int i: ans) cout << i << ' ';
    cout << endl;
    return 0;
}
