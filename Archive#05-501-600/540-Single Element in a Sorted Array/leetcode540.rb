# @param {Integer[]} nums
# @return {Integer}
def single_non_duplicate(nums)
  nums[(0..nums.size).bsearch { |i| nums[i] != nums[i^1] }]
end