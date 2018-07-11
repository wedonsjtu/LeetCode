class Solution:
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        set1 = set(nums1) & set(nums2)
        if not set1:
            return []
        dict1 = dict()
        for ele in set1:
            dict1[ele] = [0, 0]
        for i in nums1:
            if i in set1:
                dict1[i][0] += 1
        for i in nums2:
            if i in set1:
                dict1[i][1] += 1
        ans = []
        for key in dict1:
            for j in range(min(dict1[key])):
                ans.append(key)
        return ans


sol = Solution()
print(sol.intersect([2, 1, 2, 1], [2, 2]))
print(sol.intersect([1, 2, 2, 1], [2]))
print(sol.intersect([1, 2, 3, 2, 1], [2, 3, 2]))
