class Solution:
    def selfDividingNumbers(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: List[int]
        """
        if right <= 9 and left != 0:
            return [i for i in range(left, right + 1)]

        def sDN(num):
            if 0 < num < 10:
                return True
            s = str(num)
            for i in s:
                if i == '0' or num % int(i) != 0:
                    return False
            return True

        return [ii for ii in range(left, right + 1) if sDN(ii)]


sol = Solution()
print(sol.selfDividingNumbers(100, 222))