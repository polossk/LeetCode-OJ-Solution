# @param {Integer[]} nums
# @return {Void} Do not return anything, modify nums in-place instead.
def move_zeroes(nums)
  non_zeros = 0
  (0...nums.length).each {|i|
    if nums[i] != 0 then
      nums[i], nums[non_zeros] = nums[non_zeros], nums[i]
      non_zeros += 1
    end
  }
end