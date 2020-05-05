#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
    
private:
    int mergeSort(vector<int>& nums, int begin, int end) {
        if (begin >= end) return 0;
        int mid = begin + (end - begin) / 2;
        int count = mergeSort(nums, begin, mid) + 
                    mergeSort(nums, mid+1, end);
        for (int i=begin, j=mid+1; i <= mid; ++i) {
            while (j <= end && (long long)(nums[i]) > (long long)2 * (long long)(nums[j])) ++j;
            count += j - (mid + 1);
        }
        merge(nums, begin, mid, end);
        return count;
    }
    
    void merge(vector<int>& A, int start, int mid, int end) {
        // https://leetcode.com/problems/reverse-pairs/solution/
        int n1 = (mid - start + 1);
        int n2 = (end - mid);
        // vector<int> L(n1, 0), R(n2, 0);
        int L[n1], R[n2];
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
    cout << Solution().reversePairs(v) << endl;
    return 0;
}
