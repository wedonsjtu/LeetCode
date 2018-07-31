class Solution:
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        d = {}
        for s in strs:
            key = tuple(sorted(s))
            if key in d:
                d[key].append(s)
            else:
                d[key] = [s]
        return list(d.values())


sol = Solution()
print(sol.groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"]))
print(sol.groupAnagrams(["eat"]))
print(sol.groupAnagrams([""]))
print(sol.groupAnagrams([]))
