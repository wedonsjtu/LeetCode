class Solution:
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        tmp = 0
        best = 0
        n = 0
        for i in range(len(nums) - 1):
            tmp = max(tmp, i + nums[i])
            if i == best:
                n += 1
                best = tmp
                if best >= len(nums) - 1:
                    return n
        return n


sol = Solution()
print(sol.jump([1]))
print(sol.jump([2, 3, 1, 1, 4]))
