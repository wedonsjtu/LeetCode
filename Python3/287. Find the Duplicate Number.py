class Solution:
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        s = set()
        for i in nums:
            if i in s:
                return i
            else:
                s.add(i)


sol = Solution()
print(sol.findDuplicate([1, 3, 4, 2, 2]))
print(sol.findDuplicate([3, 1, 3, 4, 2]))
print(sol.findDuplicate([3, 1, 5, 4, 4, 2]))
print(sol.findDuplicate([2, 2, 2]))
