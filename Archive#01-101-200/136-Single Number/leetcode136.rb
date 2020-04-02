# @param {Integer[]} nums
# @return {Integer}
def single_number(nums)
  nums.inject(:^)
end