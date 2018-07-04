class Solution:
    def intersection(self, nums1, nums2):
        return list(set(nums1) & set(nums2))


l1 = [1, 2, 3, 2, 1]
l2 = [2, 2, 3]
sol = Solution()
print(sol.intersection(l1,l2))
