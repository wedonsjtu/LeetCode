class Solution:
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        for i in range(len(digits) - 1, -1, -1):
            if digits[i] != 9:
                digits[i] += 1
                return digits
            digits[i] = 0
        return [1] + digits


sol = Solution()
print(sol.plusOne([0]))
print(sol.plusOne([1, 0]))
print(sol.plusOne([1, 2, 3]))
print(sol.plusOne([1, 2, 3, 4]))
print(sol.plusOne([1, 2, 3, 9]))
print(sol.plusOne([1, 2, 9, 9]))
print(sol.plusOne([9, 2, 9, 9]))
print(sol.plusOne([9, 9, 9, 9]))
