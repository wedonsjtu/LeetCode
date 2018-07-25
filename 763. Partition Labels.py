class Solution:
    def partitionLabels(self, S):
        """
        :type S: str
        :rtype: List[int]
        """
        def merge(li, b):
            li1 = []
            for i in range(b, len(li)):
                li1 += li[i]
            return li[:b] + [li1]

        l1 = []
        l2 = []
        l3 = []
        l = -1
        for i in S:
            if i not in l1:
                l1.append(i)
                l2.append([i])
                l3.append([i])
                l += 1
            else:
                for j in range(l+1):
                    if i in l2[j]:
                        l2 = merge(l2, j)
                        l3 = merge(l3, j)
                        l3[-1].append(i)
                        l = len(l3) - 1
                        break
        return [len(x) for x in l3]


sol = Solution()
print(sol.partitionLabels("ababcbacadefegdehijhklij"))
print(sol.partitionLabels("abcdefg"))
