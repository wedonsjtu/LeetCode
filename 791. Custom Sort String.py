class Solution:
    def customSortString(self, S, T):
        """
        :type S: str
        :type T: str
        :rtype: str
        """
        if len(T) <= 1:
            return T
        l1 = ['0'] * len(T)
        l2 = [len(T)] * len(T)
        first = 0
        last = len(T) - 1
        for i in T:
            if i not in S:
                l1[last] = i
                last -= 1
            else:
                a = S.find(i)
                if first == 0 or l2[first - 1] <= a:
                    l1[first] = i
                    l2[first] = a
                    first += 1
                else:
                    for j in range(first):
                        if l2[j] > a:
                            for k in range(first-1, j-1, -1):
                                l1[k+1] = l1[k]
                                l2[k+1] = l2[k]
                            first += 1
                            l1[j] = i
                            l2[j] = a
                            break
        return ''.join(l1)


sol = Solution()
print(sol.customSortString("cba", "abcd"))
