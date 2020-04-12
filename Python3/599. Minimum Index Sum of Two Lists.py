class Solution:
    def findRestaurant(self, list1, list2):
        """
        :type list1: List[str]
        :type list2: List[str]
        :rtype: List[str]
        """
        l1 = set(list1) & set(list2)
        if len(l1) <= 1:
            return list(l1)
        d = {}
        m = len(list1) + len(list2)

        for i in range(len(list1)):
            if list1[i] in l1:
                if list1[i] in d:
                    d[list1[i]] += i
                    if d[list1[i]] < m:
                        m = d[list1[i]]
                else:
                    d[list1[i]] = i

        for j in range(len(list2)):
            if list2[j] in l1:
                if list2[j] in d:
                    d[list2[j]] += j
                    if d[list2[j]] < m:
                        m = d[list2[j]]
                else:
                    d[list2[j]] = j

        ans = []
        for key in d:
            if d[key] == m:
                ans.append(key)
        return ans


sol = Solution()
print(sol.findRestaurant(["Shogun", "Tapioca Express", "Burger King", "KFC"],
                         ["Piatti", "The Grill at Torrey Pines",
                          "Hungry Hunter Steakhouse", "Shogun"]))
print(sol.findRestaurant(["Shogun", "Tapioca Express", "Burger King", "KFC"],
                         ["KFC", "Shogun", "Burger King"]))
print(sol.findRestaurant(["Shogun", "Tapioca Express", "Burger King", "KFC"],
                         ["KFC", "Burger King"]))
