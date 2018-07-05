class Solution:
    def numJewelsInStones(self, J, S):
        """
        :type J: str
        :type S: str
        :rtype: int
        """
        if not (J and S):
            return 0
        a = 0
        for i in S:
            if i in J:
                a += 1
        return a


sol = Solution()
print(sol.numJewelsInStones("JS", "wSqweqeJwqeS"))
