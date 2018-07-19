class Solution:
    def readBinaryWatch(self, num):
        """
        :type num: int
        :rtype: List[str]
        """
        d1 = [[] for x in range(5)]
        for i in range(12):
            x = bin(i)[2:].count('1')
            if x < 5:
                d1[x].append(i)
        d2 = [[] for x in range(7)]
        for i in range(60):
            x = bin(i)[2:].count('1')
            if x < 7:
                d2[x].append(i)
        ans = []
        for i in range(min(5, num + 1)):
            j = num - i
            if j > 6:
                continue
            for k1 in d1[i]:
                for k2 in d2[j]:
                    ans.append(str(k1) + ':{:0>2}'.format(k2))
        return ans


sol = Solution()
for i in range(1, 11):
    print(i, sol.readBinaryWatch(i))
