class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        non_zeros = 0
        for i in range(len(nums)):
            if nums[i]:
                nums[i], nums[non_zeros] = nums[non_zeros], nums[i]
                non_zeros += 1