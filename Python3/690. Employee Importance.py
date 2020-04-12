# Employee info
class Employee:
    def __init__(self, id, importance, subordinates):
        # It's the unique id of each node.
        # unique id of this employee
        self.id = id
        # the importance value of this employee
        self.importance = importance
        # the id of direct subordinates
        self.subordinates = subordinates


class Solution:
    def getImportance(self, employees, id):
        """
        :type employees: list[Employee]
        :type id: int
        :rtype: int
        """
        for i in employees:
            if i.id == id:
                ans = i.importance
                for j in i.subordinates:
                    ans += self.getImportance(employees, j)
                return ans


# [[1,2,[2]], [2,3,[]]], 2
# 3

# [[1, 5, [2, 3]], [2, 3, []], [3, 3, []]], 1
# 11
