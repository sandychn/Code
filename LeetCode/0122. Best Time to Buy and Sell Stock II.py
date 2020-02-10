# Time  : 68 ms (80.95%)
# Memory: 14.3 MB (54.90%)

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0
        buyPrice = prices[0]
        ans = 0
        for price in prices:
            if buyPrice < price:
                ans += price - buyPrice
            buyPrice = price
        return ans
