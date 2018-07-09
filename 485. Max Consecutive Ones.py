class Solution:
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l = [0]
        for i in nums:
            if i == 1:
                l[-1] += 1
            elif l[-1] != 0:
                l.append(0)
        return max(l)


sol = Solution()
print(sol.findMaxConsecutiveOnes([1, 1, 0, 1, 1, 1]))
