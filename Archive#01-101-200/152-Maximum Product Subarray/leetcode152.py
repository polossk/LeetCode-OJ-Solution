class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        ret, tmp_p, tmp_n = nums[0], nums[0], nums[0]
        for elem in nums[1:]:
            positive = max(max(elem * tmp_p, elem * tmp_n), elem)
            negative = min(min(elem * tmp_p, elem * tmp_n), elem)
            ret = max(positive, ret)
            tmp_p, tmp_n = positive, negative
        return ret