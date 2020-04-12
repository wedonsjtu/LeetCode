class Solution:
    def nextGreaterElement(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        l = [-1] * len(nums1)
        for i in range(len(nums1)):
            k = 0
            for k in range(len(nums2)):
                if nums2[k] == nums1[i]:
                    break
            for j in range(k + 1, len(nums2)):
                if nums2[j] > nums1[i]:
                    l[i] = nums2[j]
                    break
        return l


sol = Solution()
print(sol.nextGreaterElement([4, 1, 2], [1, 3, 4, 2]))
print(sol.nextGreaterElement([2, 4], [1, 2, 3, 4]))
