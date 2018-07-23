class Solution:
    def thirdMax(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        flag = [False, False, False]
        m = [0, 0, 0]
        for i in nums:
            if not flag[2]:
                m[2] = i
                flag[2] = True
                continue
            if m[2] == i:
                continue
            if not flag[1]:
                flag[1] = True
                if i > m[2]:
                    m[1] = i
                else:
                    m[1] = m[2]
                    m[2] = i
                continue
            if m[1] == i:
                continue
            if flag[0] and m[0] == i:
                continue
            if not flag[0]:
                flag[0] = True
                if i > m[1]:
                    m[0] = i
                elif i > m[2]:
                    m[0] = m[1]
                    m[1] = i
                else:
                    m[0] = m[1]
                    m[1] = m[2]
                    m[2] = i
            else:
                if i > m[0]:
                    m[2] = m[1]
                    m[1] = m[0]
                    m[0] = i
                elif i > m[1]:
                    m[2] = m[1]
                    m[1] = i
                elif i > m[2]:
                    m[2] = i

        if not flag[0]:
            return m[1] if flag[1] else m[2]
        return m[2]


sol = Solution()
print(sol.thirdMax([1]))
print(sol.thirdMax([1, 2]))
print(sol.thirdMax([1, 2, 3]))
print(sol.thirdMax([1, 2, 3, 3]))
print(sol.thirdMax([1, 2, 2, 3, 3]))
print(sol.thirdMax([3, 2, -1, -2, 2]))
