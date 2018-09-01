class Solution:
    def checkPerfectNumber(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num <= 0:
            return False
        i = 1
        s = 0
        while i * i <= num:
            if num % i == 0:
                s += i
                if i * i != num:
                    s += num // i
            i += 1
        return s - num == num


sol = Solution()
for ii in range(10001):
    if sol.checkPerfectNumber(ii):
        print(ii)
