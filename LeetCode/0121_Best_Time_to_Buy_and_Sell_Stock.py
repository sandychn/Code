# Time  : 72 ms (76.25%)
# Memory: 14.5 MB (53.21%)

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0
        ans = 0
        minValue = prices[0]
        for price in prices:
            ans = max(ans, price - minValue)
            minValue = min(minValue, price)
        return ans
