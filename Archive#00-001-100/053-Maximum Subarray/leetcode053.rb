# @param {Integer[]} nums
# @return {Integer}
def max_sub_array(nums)
  tmp, ret = 0, -2**31
  nums.each { |elem|
    tmp = tmp > 0 ? tmp + elem : elem
    ret = ret > tmp ? ret : tmp
  }
  ret
end