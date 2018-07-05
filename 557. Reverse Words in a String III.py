class Solution:
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """

        l = s.rstrip(' ').split(' ')
        return ' '.join([o[::-1] for o in l])


sol = Solution()
print(sol.reverseWords("Let's take LeetCode contest"))