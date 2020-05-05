#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if (nums.empty()) return 0;
        int n = nums.size();
        // vector<long long> sums(n, 0);
        // sums[0] = nums[0];
        // for (int i = 1; i < n; ++i) sums[i] = sums[i-1] + nums[i];
        // return mergeSort(sums, 0, n-1, lower, upper);
        vector<long long> sums(n+1, 0);
        for (int i = 1; i < n+1; ++i) sums[i] = sums[i-1] + nums[i-1];
        return mergeSort(sums, 0, n, lower, upper);
    }

private:
    int mergeSort(vector<long long>& nums, int begin, int end, int lower, int upper) {
        if (begin >= end) return 0;
        int mid = begin + (end - begin) / 2;
        int count = mergeSort(nums, begin, mid, lower, upper) + 
                    mergeSort(nums, mid+1, end, lower, upper);
        for (int i=begin, j1=mid+1, j2=mid+1; i <= mid; ++i) {
            while (j1 <= end && nums[j1] - nums[i] < lower) j1++; 
            while (j2 <= end && nums[j2] - nums[i] <= upper) j2++;
            count += j2 - j1;
        }
        // for (long long i: nums) cout << i << ' ';
        // cout << '|' << ' ';
        merge(nums, begin, mid, end);
        // for (long long i: nums) cout << i << ' ';
        // cout << endl;
        return count;
    }
    
    void merge(vector<long long>& A, int start, int mid, int end) {
        // https://leetcode.com/problems/reverse-pairs/solution/
        int n1 = (mid - start + 1);
        int n2 = (end - mid);
        // vector<int> L(n1, 0), R(n2, 0);
        long long L[n1], R[n2];
        for (int i = 0; i < n1; i++)
            L[i] = A[start + i];
        for (int j = 0; j < n2; j++)
            R[j] = A[mid + 1 + j];
        int i = 0, j = 0;
        for (int k = start; k <= end; k++) {
            if (j >= n2 || (i < n1 && L[i] <= R[j]))
                A[k] = L[i++];
            else
                A[k] = R[j++];
        }
    }
};

int main() {
    vector<int> v{1,3,2,3,1};
    cout << Solution().countRangeSum(v,1,4) << endl;
    return 0;
}
