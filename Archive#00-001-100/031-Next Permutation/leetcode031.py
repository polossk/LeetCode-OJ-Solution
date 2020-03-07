from typing import List

class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i, j = len(nums) - 2, len(nums) - 1
        while i >= 0 and nums[i] >= nums[i + 1]: i -= 1
        if i >= 0:
            while nums[j] <= nums[i]: j -= 1
            nums[i], nums[j] = nums[j], nums[i]
        i, j = i + 1, len(nums) - 1
        while i < j:
            nums[i], nums[j] = nums[j], nums[i]
            i += 1
            j -= 1
        # print('=>', nums)


# Solution().nextPermutation([1, 2, 3])
# Solution().nextPermutation([1, 3, 2])
# Solution().nextPermutation([3, 2, 1])
# Solution().nextPermutation([1, 1, 5])
