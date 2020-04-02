# @param {Integer[]} nums
# @return {Integer}
def max_product(nums)
  ret, tmp_p, tmp_n = nums[0], nums[0], nums[0]
  nums[1..-1].each { |elem|
    positive = [[elem * tmp_p, elem * tmp_n].max, elem].max
    negative = [[elem * tmp_p, elem * tmp_n].min, elem].min
    ret = ret > positive ? ret : positive
    tmp_p, tmp_n = positive, negative
  }
  ret
end