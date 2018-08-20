class Solution:
    def countOfAtoms(self, formula):
        """
        :type formula: str
        :rtype: str
        """
        ans = {}
        i = 0
        from collections import Counter
        flag = False
        list1 = []
        while i < len(formula):
            if not flag and ord('A') <= ord(formula[i]) <= ord('Z'):
                atom = formula[i]
                while i + 1 < len(formula) and ord('a') <= ord(formula[i + 1]) <= ord('z'):
                    i += 1
                    atom += formula[i]
                nums = ''
                while i + 1 < len(formula) and ord('0') <= ord(formula[i + 1]) <= ord('9'):
                    i += 1
                    nums += formula[i]
                if not nums:
                    nums = 1
                else:
                    nums = int(nums)
                if atom in ans:
                    ans[atom] += nums
                else:
                    ans[atom] = nums
            else:
                flag = True
                if ord('A') <= ord(formula[i]) <= ord('Z'):
                    atom = formula[i]
                    while i + 1 < len(formula) and ord('a') <= ord(formula[i + 1]) <= ord('z'):
                        i += 1
                        atom += formula[i]
                    nums = ''
                    while i + 1 < len(formula) and ord('0') <= ord(formula[i + 1]) <= ord('9'):
                        i += 1
                        nums += formula[i]
                    if not nums:
                        nums = 1
                    else:
                        nums = int(nums)
                    if atom in list1[-1]:
                        list1[-1][atom] += nums
                    else:
                        list1[-1][atom] = nums
                elif formula[i] == '(':
                    list1.append(dict())
                else:
                    nums = ''
                    while i + 1 < len(formula) and ord('0') <= ord(formula[i + 1]) <= ord('9'):
                        i += 1
                        nums += formula[i]
                    if not nums:
                        nums = 1
                    else:
                        nums = int(nums)
                    for ii in list1[-1]:
                        list1[-1][ii] *= nums
                    if len(list1) >= 2:
                        list1[-2] = dict(Counter(list1[-2]) + Counter(list1[-1]))
                        list1.pop()
                    elif len(list1) == 1:
                        ans = dict(Counter(ans) + Counter(list1[0]))
                        list1 = []
                        flag = False
            i += 1
        ans = list(ans.items())
        ans.sort(key=lambda x: x[0])
        res = ""
        for i in ans:
            res += i[0]
            if i[1] != 1:
                res += str(i[1])
        return res


sol = Solution()
print(sol.countOfAtoms("Au2((SO2)4(KWO)3Hg)2(Ag3)2CO3"))
print(sol.countOfAtoms("(N13O9Be)37(LiC50B35)38(Li33HHBe14He5ON50N)27(H3C)2He14C34Li33C33He15N14N5Li24Li17H28O13H42("
                       "HeHe6CO11Li)35(He3O27HO5N21H49O39CH37B3)8(O41He27He46He22He17)12"))
