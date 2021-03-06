class Solution:
    def triangleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        ans = 0
        for i in range(len(nums) - 2):
            k = i + 2
            j = i + 1
            while j < len(nums) - 1 and nums[i] != 0:
                while k < len(nums) and nums[i] + nums[j] > nums[k]:
                    k += 1
                ans += k - j - 1
                j += 1
        return ans


sol = Solution()
print(sol.triangleNumber([2, 2, 3, 4]))
print(sol.triangleNumber([2, 2, 3, 5]))
print(sol.triangleNumber([2, 1, 3, 7]))
