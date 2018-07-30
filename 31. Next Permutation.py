class Solution:
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        flag = False
        i = len(nums)-2
        while i > -1:
            if nums[i] >= nums[i+1]:
                i -= 1
                continue
            flag = True
            break
        if not flag:
            nums.sort()
            return
        j = len(nums) - 1
        while j >= 0 and nums[j] <= nums[i]:
            j -= 1
        nums[j], nums[i] = nums[i], nums[j]
        j = len(nums)-1
        i = i+1
        while i < j:
            nums[j], nums[i] = nums[i], nums[j]
            i += 1
            j -= 1


sol = Solution()
l1 = [1, 81, 9]
sol.nextPermutation(l1)
print(l1)
l1 = [1, 4, 8]
sol.nextPermutation(l1)
print(l1)
l1 = [3, 2, 1]
sol.nextPermutation(l1)
print(l1)
