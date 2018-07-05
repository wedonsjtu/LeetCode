class Solution:
    def findComplement(self, num):
        """
        :type num: int
        :rtype: int
        """
        s = bin(num)[2:]
        return int(''.join([chr(ord('1')-int(o)) for o in s]), 2)


sol = Solution()
print(sol.findComplement(12324))
