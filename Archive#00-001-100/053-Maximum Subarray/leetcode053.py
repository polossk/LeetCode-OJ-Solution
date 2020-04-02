class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        tmp, ret = 0, -2**31
        for elem in nums:
            tmp = max(elem, tmp + elem)
            ret = max(ret, tmp)
        return ret