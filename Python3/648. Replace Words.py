class Solution:
    def replaceWords(self, dict, sentence):
        """
        :type dict: List[str]
        :type sentence: str
        :rtype: str
        """
        dict = set(dict)
        ans = []
        list1 = sentence.split()
        for i in list1:
            for ii in range(1, len(i)):
                if i[:ii] in dict:
                    ans.append(i[:ii])
                    break
            else:
                ans.append(i)
        return ' '.join(ans)


sol = Solution()
print(sol.replaceWords(["cat", "bat", "rat"], "the cattle was rattled by the battery"))
