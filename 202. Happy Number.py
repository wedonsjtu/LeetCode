class Solution:
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        ans = 0
        while n != 0:
            ans += (n % 10) ** 2
            n = n // 10
        if ans == 1 or ans == 7:
            return True
        if 0 <= ans <= 9:
            return False
        return self.isHappy(ans)


sol = Solution()
#print(sol.isHappy(1111111))
#print(sol.isHappy(12))
for i in range(0, 10001):
    print(i, sol.isHappy(i))
