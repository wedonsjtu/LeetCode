class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if not prices:
            return 0
        min_price = prices[0]
        max_profit = 0
        for i in prices:
            if i < min_price:
                min_price = i
            else:
                max_profit = max(max_profit, i - min_price)
        return max_profit


sol = Solution()
print(sol.maxProfit([7,1,5,3,6,4]))
print(sol.maxProfit([7,6,4,3,1]))
print(sol.maxProfit([1]))
