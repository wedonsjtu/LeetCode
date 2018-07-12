class Solution:
    def rotatedDigits(self, N):
        """
        :type N: int
        :rtype: int
        """
        ros = ('0', '1', '8')
        rod = ('2', '5', '6', '9')
        nro = ('3', '4', '7')

        def goodNumber(n):
            s = str(n)
            flag = False
            for i in s:
                if i in nro:
                    return False
                if i in rod:
                    flag = True
            return flag

        ans = 0
        for ii in range(1, N + 1):
            if goodNumber(ii):
                ans += 1
        return ans


sol = Solution()
print(sol.rotatedDigits(1))
print(sol.rotatedDigits(10))
print(sol.rotatedDigits(10000))
