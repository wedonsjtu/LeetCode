class Solution:
    def matrixReshape(self, nums, r, c):
        """
        :type nums: List[List[int]]
        :type r: int
        :type c: int
        :rtype: List[List[int]]
        """
        if not nums:
            return nums
        l1 = []
        l2 = []
        for i in nums:
            for j in i:
                l1.append(j)
        if r * c != len(l1):
            return nums
        for i in range(r):
            l2.append(l1[i * c:(i + 1) * c])
        return l2


sol = Solution()
print(sol.matrixReshape([[1, 2], [3, 4]], 1, 4))
print(sol.matrixReshape([[1, 2], [3, 4]], 4, 1))
print(sol.matrixReshape([[1, 2], [3, 4]], 3, 1))
