class Solution:
    def allPathsSourceTarget(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: List[List[int]]
        """
        n = len(graph)
        if len(graph) == 1:
            return [[0]]
        ans = []

        def aPST(path, node):
            """
            :type path: list[int]
            :type node: int
            """
            if node == n - 1:
                ans.append(path)
                return
            for i in graph[node]:
                aPST(path + [i], i)

        aPST([0], 0)
        return ans


sol = Solution()
print(sol.allPathsSourceTarget([[1, 2], [3], [3], []]))
print(sol.allPathsSourceTarget([[3], [0, 1, 3], [], [2]]))
print(sol.allPathsSourceTarget([[3], [0, 1, 3], [], [2]]))
print(sol.allPathsSourceTarget([[1, 2, 3], [2], [3], []]))
