from functools import reduce

class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        flag = reduce(lambda a, b: a ^ b, nums)
        flag &= -flag
        a, b = 0, 0
        for e in nums:
            if e & flag: a ^= e
            else: b ^= e
        return [a, b]