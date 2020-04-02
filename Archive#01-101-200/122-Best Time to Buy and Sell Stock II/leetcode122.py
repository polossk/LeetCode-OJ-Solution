class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        return sum(max(0, a - b) for a, b in zip(prices[1:], prices[:-1]))