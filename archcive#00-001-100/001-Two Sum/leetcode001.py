from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        table = {}
        for i, e in enumerate(nums):
            if table.get(e) != None:
                return [table[e], i]
            table[target - e] = i
