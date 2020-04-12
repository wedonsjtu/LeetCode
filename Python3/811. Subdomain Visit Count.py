class Solution:
    def subdomainVisits(self, cpdomains):
        """
        :type cpdomains: List[str]
        :rtype: List[str]
        """
        if not cpdomains or (len(cpdomains) == 1 and cpdomains[0].count('.') == 0):
            return cpdomains
        ans = []
        d1 = {}

        def add_dict(s1, s2):
            if s2 in d1:
                d1[s2] += int(s1)
            else:
                d1[s2] = int(s1)

        for i in range(len(cpdomains)):
            l1 = cpdomains[i].split(' ')
            add_dict(l1[0], l1[1])
            i1 = l1[1].find('.')
            add_dict(l1[0], l1[1][i1+1:])
            i2 = l1[1][i1+1:].find('.')
            if i2 != -1:
                add_dict(l1[0], l1[1][i1+i2+2:])

        for i in d1:
            ans.append(str(d1[i]) + ' ' + i)
        return ans


sol = Solution()
ll = ["9001 discuss.leetcode.com"]
ll = ["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]
ll = []
ll = ["9001 leetcode.com"]
ll = ["9001 com"]
print(sol.subdomainVisits(ll))
