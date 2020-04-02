class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        a, b = 0, 0
        for e in nums:
            a = (a ^ e) & (~b)
            b = (b ^ e) & (~a)
        return a