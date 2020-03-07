class Solution:
    # dp
    def lengthOfLIS(self, nums: List[int]) -> int:
        if nums == []: return 0
        dp = [1 for _ in range(len(nums))]
        for i in range(1, len(nums)):
            hoge = [dp[j] + 1 for j in range(i) if nums[j] < nums[i]]
            dp[i] = 1 if len(hoge) == 0 else max(hoge)
        return max(dp)

    # greedy
    def lengthOfLIS(self, nums: List[int]) -> int:
        if len(nums) < 2: return len(nums)
        greedy = [nums[0]]
        for elem in nums[1:]:
            if greedy[-1] < elem:
                greedy.append(elem)
                continue
            l , r = 0, len(greedy) - 1
            while l < r:
                mid = l + (r - l) // 2
                if greedy[mid] < elem:
                    l = mid + 1
                else:
                    r = mid
            greedy[l] = elem
        return len(greedy)